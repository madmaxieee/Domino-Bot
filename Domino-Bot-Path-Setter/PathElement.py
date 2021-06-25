import json

error_prompt = json.load(open("data/error.json"))

path_commands = {'M': [2], 'l': [2], 'q': [2, 2], 's': [2, 2], 'v': [1]}


class PathElement:
    def __init__(self, type, args):
        if (len(args) != len(path_commands[type])):
            raise AttributeError(error_prompt['args-len'])
        try:
            for i in range(len(args)):
                if len(args[i]) == len(path_commands[type]):
                    continue
        except Exception as e:
            raise AttributeError(error_prompt['path-type'])
        self.type = type
        self.args = args


class M(PathElement):
    def __init__(self, *args):
        super().__init__('M', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}"


class s(PathElement):
    def __init__(self, *args):
        super().__init__('s', args)

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]} {self.args[1][0]},{self.args[1][1]}\n"


class v(PathElement):
    def __init__(self, arg):
        super().__init__('v', [(arg, )])

    def text(self):
        return f"{self.type} {self.args[0][0]}"


if __name__ == '__main__':
    c1 = s((50, 50), (100, 100))
    c2 = M(100, 100)
    c3 = v(0)
    print(c1.text())
    print(c2.text())
    print(c3.text())