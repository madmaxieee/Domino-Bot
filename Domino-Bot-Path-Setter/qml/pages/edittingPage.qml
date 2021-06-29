import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.3

Item {
    id: item1

    property url workingFile: "../../img/svg/example.svg"
    property bool rootPlaced: false

    // map to 1920x1080
    function linearMap(x, y, width, height) {
        var cord = [x * 1920 / width, y * 1080 / height]
        return cord
    }

    function reverseMap(x, y, width, height) {
        var cord = [x * width / 1920, y * height / 1080]
        return cord
    }

    Rectangle {
        id: bg
        color: "#2c313c"
        anchors.right: parent.right
        anchors.fill: parent

        Rectangle {
            id: toolBarBg
            width: 73
            color: "#7b8291"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 10
            anchors.topMargin: 10

            Column {
                id: toolBar
                anchors.fill: parent
                clip: true
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5

                CustomToolButton {
                    id: placeRootBtn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    displayText: "Root"
                    height: 30

                    onClicked: {
                        if (!rootPlaced) {
                            placeRootBtn.isActive = !placeRootBtn.isActive
                            makeLineBtn.isActive = false
                            makeCurveBtn.isActive = false
                        } else {
                            console.log("you already placed a root")
                        }
                    }
                }

                Rectangle {
                    height: 10
                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#00000000"
                }

                CustomToolButton {
                    id: makeLineBtn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    displayText: "Line"
                    height: 30

                    onClicked: {
                        makeLineBtn.isActive = !makeLineBtn.isActive
                        placeRootBtn.isActive = false
                        makeCurveBtn.isActive = false
                    }
                }

                Rectangle {
                    height: 10
                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#00000000"
                }

                CustomToolButton {
                    id: makeCurveBtn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    displayText: "Curve"
                    height: 30

                    onClicked: {
                        makeCurveBtn.isActive = !makeCurveBtn.isActive
                        makeLineBtn.isActive = false
                        placeRootBtn.isActive = false
                    }
                }

                Rectangle {
                    height: 70

                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#00000000"
                }

                CustomToolButton {
                    id: undoBtn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    displayText: "Undo"
                    height: 30

                    onClicked: {
                        placeRootBtn.isActive = false
                        makeLineBtn.isActive = false
                        makeCurveBtn.isActive = false

                        backend.undo()
                    }
                }

                Rectangle {
                    height: 10

                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#00000000"
                }

                CustomToolButton {
                    id: clearBtn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    displayText: "Clear"
                    height: 30

                    onClicked: {
                        placeRootBtn.isActive = false
                        makeLineBtn.isActive = false
                        makeCurveBtn.isActive = false

                        backend.clear()
                    }
                }
            }
        }

        Rectangle {
            id: workspace
            color: "#00000000"
            border.color: "#00000000"
            anchors.left: toolBarBg.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            clip: true
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10

            Image {
                id: edittingSVG
                source: workingFile
                anchors.bottomMargin: 0
                anchors.topMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                sourceSize.width: 1920
                sourceSize.height: 1080
                fillMode: Image.PreserveAspectFit
                antialiasing: true
                visible: true
                anchors.top: parent.top
                anchors.bottom: parent.bottom
            }

            Rectangle {
                id: workspaceBprder
                color: "#00000000"
                border.color: "#3494cb"
                anchors.left: edittingSVG.left
                anchors.right: edittingSVG.right
                anchors.top: edittingSVG.top
                anchors.bottom: edittingSVG.bottom

                // root and end point
                Image {
                    id: rootDot
                    source: "../../img/svg/root_end.svg"
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    sourceSize.width: 1000
                    sourceSize.height: 1000
                    width: 10
                    height: 10
                    fillMode: Image.PreserveAspectFit
                    visible: false
                    anchors.left: parent.left
                    anchors.top: parent.top
                    antialiasing: true
                }

                // change the color of the svg icon
                ColorOverlay {
                    id: rootDotOverlay
                    anchors.fill: rootDot
                    source: rootDot
                    color: "#FFFFFF"
                    antialiasing: true
                    width: rootDot.width
                    height: rootDot.height
                }

                // root and end point
                Image {
                    id: endDot
                    source: "../../img/svg/root_end.svg"
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    sourceSize.width: 1000
                    sourceSize.height: 1000
                    width: 10
                    height: 10
                    fillMode: Image.PreserveAspectFit
                    visible: false
                    anchors.left: parent.left
                    anchors.top: parent.top
                    antialiasing: true
                }

                // change the color of the svg icon
                ColorOverlay {
                    id: endDotOverlay
                    anchors.fill: endDot
                    source: endDot
                    color: "#10e64b"
                    antialiasing: true
                    width: endDot.width
                    height: endDot.height
                }
            }

            MouseArea {
                id: paintingArea
                anchors.left: edittingSVG.left
                anchors.right: edittingSVG.right
                anchors.top: edittingSVG.top
                anchors.bottom: edittingSVG.bottom
                property var cord: [0, 0]

                onClicked: {
                    paintingArea.cord = linearMap(paintingArea.mouseX,
                                                  paintingArea.mouseY,
                                                  paintingArea.width,
                                                  paintingArea.height)
                    if (placeRootBtn.isActive) {
                        rootPlaced = true
                        placeRootBtn.isActive = false
                        backend.placeRoot(cord[0], cord[1])
                    } else if (makeLineBtn.isActive) {
                        backend.drawLine(cord[0], cord[1])
                    } else if (makeCurveBtn.isActive) {
                        backend.drawCurve(cord[0], cord[1])
                    }
                }
            }
        }
    }

    MessageDialog {
        id: pathWarningDialog1
        title: "Warning"
        text: "Invalid path!\n\nNew path intersecting existing path."
    }

    Connections {
        target: backend

        function onSvgPath(path) {
            workingFile = path
        }

        function onReloadSvg() {
            var temp = workingFile
            workingFile = "../../img/svg/blank.svg"
            workingFile = temp
        }

        function onUpdateRoot(x, y) {
            if (x === -1 && y === -1) {
                rootDotOverlay.visible = false
                rootPlaced = false
            } else {
                rootDotOverlay.visible = true
                var cord = reverseMap(x, y, paintingArea.width,
                                      paintingArea.height)
                rootDot.anchors.leftMargin = cord[0] - rootDot.width / 2
                rootDot.anchors.topMargin = cord[1] - rootDot.height / 2
            }
        }

        function onUpdateEnd(x, y) {
            if (x === -1 && y === -1) {
                endDotOverlay.visible = false
            } else {
                endDotOverlay.visible = true
                var cord = reverseMap(x, y, paintingArea.width,
                                      paintingArea.height)
                endDot.anchors.leftMargin = cord[0] - endDot.width / 2
                endDot.anchors.topMargin = cord[1] - endDot.height / 2
            }
        }

        function onInvalidPathWarning() {
            console.log("invalid!")
            pathWarningDialog1.open()
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

