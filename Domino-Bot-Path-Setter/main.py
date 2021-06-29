# This Python file uses the following encoding: utf-8
import os
import sys

from PySide2.QtGui import QGuiApplication
from PySide2.QtQml import QQmlApplicationEngine

from backend import BackEnd

if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    app.setOrganizationName("zhuang, jia xu")
    app.setOrganizationDomain("N/A")

    # Get Context
    be = BackEnd()
    engine.rootContext().setContextProperty("backend", be)

    # Load QML File
    engine.load(os.path.join(os.path.dirname(__file__), "qml/main.qml"))

    if not engine.rootObjects():
        sys.exit(-1)
    sys.exit(app.exec_())
