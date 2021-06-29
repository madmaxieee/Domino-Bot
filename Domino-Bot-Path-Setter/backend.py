from PySide2.QtCore import QObject, Slot, Signal, QUrl
from vpython.vpython import points
from svg_file import SvgFile
import PathElement as elem

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
    def openFile(self, filePath):
        self.working_path = QUrl(filePath).toLocalFile()
        self.working_file = SvgFile(self.working_path)
        self.working_file.test()
        self.svgPath.emit(f'file:///{self.working_path}')
        root = self.working_file.getRoot()
        self.updateRoot.emit(root[0], root[1])
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])

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

    reloadSvg = Signal()
    invalidPath = Signal()

    @Slot(float, float)
    def placeRoot(self, X, Y):
        self.points = [[X, Y]]
        self.working_file.append(elem.M(X,Y))
        self.working_file.save()
        self.updateRoot.emit(X, Y)

    @Slot(float, float)
    def drawLine(self, X, Y):
        self.points.append([X, Y])
        self.working_file.append(elem.L(X, Y))
        self.working_file.save()
        self.reloadSvg.emit()
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])
        print("reload!")

    @Slot(float, float)
    def drawCurve(self, X, Y):
        self.points.append([X, Y])
        self.working_file.append(elem.T(X, Y))
        self.working_file.save()
        self.reloadSvg.emit()
        end = self.working_file.getEnd()
        self.updateEnd.emit(end[0], end[1])
        print("reload!")

    clearRoot = Signal()

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