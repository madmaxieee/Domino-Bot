import json

class PathElement:

    _error_prompt = json.load(open("data/error.json"))

    _path_commands = {'M': [2], 'l': [2], 'L': [2], 'q': [2, 2],'T': [2], 't': [2], 's': [2, 2], 'v': [1]}

    def __init__(self, type, args):
        if (len(args) != len(self._path_commands[type])):
            raise AttributeError(self._error_prompt['args-len'])
        try:
            for i in range(len(args)):
                if len(args[i]) == len(self._path_commands[type]):
                    continue
        except Exception as e:
            raise AttributeError(self._error_prompt['path-type'])
        self.type = type
        self.args = args


class M(PathElement):
    def __init__(self, *args):
        super().__init__('M', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}\n\t\t\t"


class L(PathElement):
    def __init__(self, *args):
        super().__init__('L', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}\n\t\t\t"

class l(PathElement):
    def __init__(self, *args):
        super().__init__('l', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}\n\t\t\t"
class s(PathElement):
    def __init__(self, *args):
        super().__init__('s', args)

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]} {self.args[1][0]},{self.args[1][1]}\n\t\t\t"

class T(PathElement):
    def __init__(self, *args):
        super().__init__('T', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}\n\t\t\t"
class t(PathElement):
    def __init__(self, *args):
        super().__init__('t', [args])

    def text(self):
        return f"{self.type} {self.args[0][0]},{self.args[0][1]}\n\t\t\t"


class v(PathElement):
    def __init__(self, arg):
        super().__init__('v', [(arg, )])

    def text(self):
        return f"{self.type} {self.args[0][0]}\n\t\t\t"


if __name__ == '__main__':
    c1 = s((50, 50), (100, 100))
    c2 = t(100, 100)
    c3 = v(0)
    print(c1.text())
    print(c2.text())
    print(c3.text())