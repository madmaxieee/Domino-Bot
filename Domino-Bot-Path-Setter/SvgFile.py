import json
import PathElement as pe

data_file = json.load(open("data/data.json"))
class SvgFile:
    def __init__(self, filename):
        self.file_name = filename
        self.__file = None

        try:
            self.__file = open(self.file_name, 'r')
            self.__raw_data = self.__file.readlines()
        except Exception as e:
            self.__file = open(self.file_name, 'x')
            self.__raw_data = []

        self.__file.close()

        self.__last_found = ""
        self.__last_found_idx = [-1, -1]

        if self.__find(data_file['svg-close']) == (-1, -1):
            self.__raw_data = []
            self.__raw_data.append(data_file['svg-heading'])
            self.__raw_data.append(data_file['svg-base-element'])
            self.__raw_data.append(data_file['path-tag'])
            self.__raw_data.append(data_file['svg-close'])

        self.elements = []

    def __find(self, target, find_last = False, get_end = False):
        tline = -1
        tstart = -1
        found = False

        if target == self.__last_found:
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
                    if self.__raw_data[line][column] == target[0] and column + len(target) <= len(self.__raw_data[line]):
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

        if find_last:
            return self.__find(target, find_last)
        else:
            return (tline, tstart)

    def __insert(self, text):
        last_element = self.elements[-1]
        self.__find(last_element.text)

    def append(self, element):
        self.elements.append(element)
        self.__raw_data = []

    def test(self):
        for i in range(3):
            print(self.__find("123"))

    def close(self):
        self.__file = open(self.file_name, 'w')
        self.__file.writelines(self.__raw_data)
        self.__file.close()


if __name__ == "__main__":
    myFile = SvgFile("test.txt")
    print(myFile.__find('d=\"'))
    # myFile.test()
    myFile.close()
