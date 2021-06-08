import json

data_file = json.load(open("data/data.json"))

class SvgFile:
    def __init__(self, filename):
        self.file_name = filename
        self.file = None

        try:
            self.file = open(self.file_name, 'r')
            self.data = self.file.readlines()
        except Exception as e:
            self.file = open(self.file_name, 'x')
            self.data = []

        self.file.close()

        self.last_found = ""
        self.last_found_idx = [-1, -1]

        if self.find(data_file['svg-close']) == (-1, -1):
            self.data = []
            self.data.insert(0, data_file['svg-heading'])
            self.data.insert(1, data_file['svg-base-element'])
            self.data.append(data_file['svg-close'])

    def find(self, target):
        tline = -1
        tstart = -1
        found = False

        if target == self.last_found:
            line_start = self.last_found_idx[0]
            column_start = self.last_found_idx[1] + 1
        else:
            line_start = 0
            column_start = 0

        for line in range(line_start, len(self.data)):
            if not found:
                for column in range(column_start, len(self.data[line])):
                    if found:
                        break
                    if self.data[line][column] == target[0] and column + len(target) <= len(self.data[line]):
                        for i in range(len(target)):
                            if self.data[line][column + i] == target[i]:
                                if i == len(target) - 1:
                                    found = True
                                    tline = line
                                    tstart = column
                                else:
                                    continue
                            else:
                                break

        self.last_found_idx = [tline, tstart]
        self.last_found = target

        return (tline, tstart)

    def test(self):
        for i in range(3):
            print(self.find("123"))

    def close(self):
        self.file = open(self.file_name, 'w')
        self.file.writelines(self.data)
        self.file.close()


if __name__ == "__main__":
    myFile = SvgFile("test.txt")
    myFile.test()
    myFile.close()
