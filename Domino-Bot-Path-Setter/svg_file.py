from svg_to_gcode.svg_parser import parse_file
from svg_to_gcode.compiler import Compiler, interfaces
from svg_to_gcode import TOLERANCES
from math import pi, sqrt
import re
from vpython import vector, mag, diff_angle
from pathlib import Path
from gcodeparser import GcodeParser
import json
import PathElement as elem

data_file = json.load(open("data/data.json"))


class SvgFile:
    def __init__(self, filename):
        self.file_path = filename
        self.__file = None

        try:
            self.__file = open(self.file_path, 'r')
            self.__raw_data = self.__file.readlines()
        except Exception as e:
            self.__file = open(self.file_path, 'x')
            self.__raw_data = []

        self.__file.close()

        self.__last_found = ""
        self.__last_found_idx = [-1, -1]

        if self.__find(data_file['svg-base-element']) == (-1, -1):
            self.__raw_data = []
            self.__raw_data.append(data_file['svg-heading'])
            self.__raw_data.append(data_file['svg-base-element'])
            self.__raw_data.append(data_file['path-tag'])
            self.__raw_data.append(data_file['svg-close'])

        self.save()

        self.tolerance = 2
        self.__Ard_command_path = None

    def __file_name(self):
        return re.split("[./]", self.file_path)[-2]

    def save(self):
        self.__file = open(self.file_path, 'w')
        self.__file.writelines(self.__raw_data)
        self.__file.close()

    def reload(self):
        self.save()
        del self.__file
        self.__file = open(self.file_path, 'r')
        self.__raw_data = self.__file.readlines()
        self.__file.close()
        self.__last_found = ""
        self.__last_found_idx = [-1, -1]

    def __find(self, target, reset=True):
        tline = -1
        tstart = -1
        found = False

        if not reset and target == self.__last_found:
            line_start = self.__last_found_idx[0]
            column_start = self.__last_found_idx[1] + 1
        else:
            line_start = 0
            column_start = 0

        for line in range(line_start, len(self.__raw_data)):
            if not found:
                for column in range(column_start, len(self.__raw_data[line])):
                    if found:
                        break
                    if self.__raw_data[line][column] == target[
                            0] and column + len(target) <= len(
                                self.__raw_data[line]):
                        for i in range(len(target)):
                            if self.__raw_data[line][column + i] == target[i]:
                                if i == len(target) - 1:
                                    found = True
                                    tline = line
                                    tstart = column
                                else:
                                    continue
                            else:
                                break

        self.__last_found_idx = [tline, tstart]
        self.__last_found = target

        return tline, tstart

    def append(self, element):
        line, col = self.__find("\" fill-opacity")
        data_list = []
        data_list[:0] = self.__raw_data[line]
        data_list.insert(col, element.text())
        self.__raw_data[line] = ''.join(data_list)

    def ctrlZ(self):
        self.reload()
        line, _ = self.__find("\" fill-opacity")
        if self.__raw_data[line - 1] != "\t\t\tM 0,0\n":
            self.__raw_data.pop(line - 1)
            return True
        else:
            return False

    def clear_path(self):
        while self.ctrlZ():
            pass

    def to_gcode(self):
        TOLERANCES['approximation'] = self.tolerance

        gcode_compiler = Compiler(interfaces.Gcode,
                                  movement_speed=0,
                                  cutting_speed=0,
                                  pass_depth=0)

        curves = parse_file(self.file_path, transform_origin=False)

        gcode_compiler.append_curves(curves)
        gcode_compiler.compile_to_file(f'gcode/{self.__file_name()}.gcode', passes=1)

        del gcode_compiler

    def __to_polar(self, p0, p1, p2):
        vec0 = vector(p1[0] - p0[0], p1[1] - p0[1], 0)
        vec1 = vector(p2[0] - p1[0], p2[1] - p1[1], 0)
        theta = diff_angle(vec0, vec1) * (-1 if vec0.cross(vec1).z > 0 else 1)
        r = mag(vec1)
        return f'{theta*180/pi:+04.0f} {r:03.0f}\n'

    def to_Arduino_Command(self, path=None):
        if self.__Ard_command_path == None and path == None:
            self.__Ard_command_path = Path(
                f'ArduinoCommand/{self.__file_name()}.txt')
        elif self.__Ard_command_path == None and path != None:
            self.__Ard_command_path = path

        target_path = self.__Ard_command_path

        # load file
        try:
            command_file = open(target_path, 'r')
        except Exception as e:
            command_file = open(target_path, 'x')
        command_file.close()
        command_text = []
        self.to_gcode()

        with open(f'gcode/{self.__file_name()}.gcode') as f:
            gcode = f.read()
        parsed_gcode = GcodeParser(gcode)
        gline_list = parsed_gcode.lines
        i = 0
        while i in range(len(gline_list)):
            if gline_list[i].command[0] != 'G' or gline_list[i].get_param(
                    'X', default='dne') == 'dne':
                del gline_list[i]
                i -= 1
            i += 1

        cords = []
        for gline in gline_list:
            cords.append([gline.get_param('X'), gline.get_param('Y')])

        try:
            r1 = sqrt((cords[0][0] - cords[1][0])**2 + (cords[0][1] - cords[1][1])**2)
            command_text.append(f'+000 {r1:03.0f}\n')
            for j in range(len(cords) - 2):
                command_text.append(self.__to_polar(cords[j], cords[j + 1], cords[j + 2]))
        except:
            pass
        # save the file
        command_file = open(target_path, 'w')
        command_file.writelines(command_text)
        command_file.close()

        return cords

    def getEnd(self):
        cords = self.to_Arduino_Command()
        return cords[-1] if len(cords) > 1 else [-1, -1]

    def getRoot(self):
        cords = self.to_Arduino_Command()
        return cords[0] if len(cords) > 0 else [-1, -1]

    def test(self):
        print("import seccessful!")
        print(self.file_path)


if __name__ == "__main__":
    myFile = SvgFile("test.svg")
    myFile.clear_path()
    myFile.append(elem.M(100, 100))
    myFile.append(elem.l(1400, 0))
    myFile.append(elem.l(0, 800))
    myFile.append(elem.l(-1400, 0))
    myFile.append(elem.l(0, -800))
    myFile.save()
    myFile.to_Arduino_Command()
