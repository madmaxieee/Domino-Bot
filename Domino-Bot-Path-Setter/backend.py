from PySide2.QtCore import QObject, Slot, Signal, QUrl
from svg_file import SvgFile
from myMath import cross, intersect
import PathElement as elem
import json

settings_file = json.load(open("data/settings.json"))


class BackEnd(QObject):
    def __init__(self):
        QObject.__init__(self)
        self.working_path = None
        self.working_file = None
        self.points = []

    svgPath = Signal(str)

    # returns [-1, -1] if not available
    updateRoot = Signal(float, float)
    updateEnd = Signal(float, float)

    @Slot()
    def resize(self):
        root = self.working_file.getRoot()
        self.updateRoot.emit(root[0], root[1])
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])

    @Slot(str)
    def openFile(self, filePath='last_used'):
        if filePath == 'last_used':
            if settings_file['last_used'] == "None":
                return
            elif self.working_path == None:
                self.working_path = settings_file['last_used']
        else:
            self.working_path = QUrl(filePath).toLocalFile()

        if self.working_file != None:
            del self.working_file

        self.working_file = SvgFile(self.working_path)
        self.working_file.test()
        self.svgPath.emit(f'file:///{self.working_path}')
        root = self.working_file.getRoot()
        self.updateRoot.emit(root[0], root[1])
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])

        settings_file['last_used'] = self.working_path
        with open('data/settings.json', 'w') as outfile:
            json.dump(settings_file, outfile)

    @Slot()
    def saveFile(self):
        if self.working_file != None:
            self.working_file.save()
        else:
            print("can\'t save, file not created yet")

    checkFileOpened = Signal(bool)

    @Slot()
    def checkFile(self):
        self.checkFileOpened.emit(self.working_file != None)
        return self.working_file != None

    reloadSvg = Signal()
    invalidPath = Signal()

    @Slot(float, float)
    def placeRoot(self, X, Y):
        self.points = [[X, Y]]
        self.working_file.append(elem.M(X,Y))
        self.working_file.save()
        self.updateRoot.emit(X, Y)

    def isValidPath(self, P: list):
        A1 = self.points[-1]
        A2 = P
        for i in range(len(self.points) - 2):
            if intersect(A1, A2, self.points[i], self.points[i+1]):
                return False
        return True

    invalidPathWarning = Signal()

    @Slot(float, float)
    def drawLine(self, X, Y):
        P = [X, Y]
        if not self.isValidPath(P):
            self.invalidPathWarning.emit()
            return
        self.points.append(P)
        self.working_file.append(elem.L(X, Y))
        self.working_file.save()
        self.reloadSvg.emit()
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])
        print("reload!")

    @Slot(float, float)
    def drawCurve(self, X, Y):
        P = [X, Y]
        if not self.isValidPath(P):
            self.invalidPathWarning.emit()
            return
        self.points.append(P)
        self.working_file.append(elem.T(X, Y))
        self.working_file.save()
        self.reloadSvg.emit()
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])
        print("reload!")

    @Slot()
    def undo(self):
        self.working_file.ctrlZ()
        self.working_file.save()
        if len(self.points) > 0:
            del self.points[-1]
        root = self.working_file.getRoot()
        self.updateRoot.emit(root[0], root[1])
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])
        self.reloadSvg.emit()
        print('undo')

    @Slot()
    def clear(self):
        self.working_file.clear_path()
        self.working_file.save()
        self.points = []
        self.updateRoot.emit(-1, -1)
        self.updateEnd.emit(-1, -1)
        self.reloadSvg.emit()
        print('clear')

    @Slot()
    def convert(self):
        if self.checkFile():
            dirList = []
            dirList[:] = self.working_path
            dirList[-4:] = '_command.txt'
            dirStr = ''.join(dirList)
            self.working_file.to_Arduino_Command(dirStr)

    if __name__ == '__main__':
        l1 = [0, 20]
        l1 = [max(l1), min(l1)]
        print(l1)
