import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "controls/"

Window {
    id: window
    width: 1000
    height: 580
    visible: true
    color: "#00000000"
    title: qsTr("mainWindow")

    Rectangle {
        id: bg
        color: "#2c313c"
        border.color: "#353b48"
        border.width: 1
        anchors.fill: parent
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10

        Rectangle {
            id: appContainer
            color: "#00000000"
            border.color: "#00000000"
            anchors.fill: parent
            anchors.rightMargin: 1
            anchors.leftMargin: 1
            anchors.bottomMargin: 1
            anchors.topMargin: 1

            Rectangle {
                id: topBar
                height: 60
                color: "#1a1d23"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top

                ToggleBtn {}

                Rectangle {
                    id: topMenuDescription
                    y: 35
                    height: 25
                    color: "#2c313c"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.rightMargin: 0
                    anchors.leftMargin: 70
                    anchors.bottomMargin: 0

                    Label {
                        id: labelTopinfo
                        color: "#9eaab2"
                        text: qsTr("App description")
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 300
                        anchors.leftMargin: 10
                    }

                    Label {
                        id: labelTopRightinfo
                        color: "#9eaab2"
                        text: qsTr("| Home")
                        anchors.left: labelTopinfo.right
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 10
                        anchors.leftMargin: 0
                    }
                }

                Rectangle {
                    id: titleBar
                    height: 35
                    color: "#00000000"
                    border.color: "#00000000"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.rightMargin: 105
                    anchors.leftMargin: 70
                    anchors.topMargin: 0

                    Image {
                        id: image
                        width: 28
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        source: "qrc:/qtquickplugin/images/template_image.png"
                        anchors.bottomMargin: 0
                        anchors.topMargin: 0
                        anchors.leftMargin: 5
                        fillMode: Image.PreserveAspectFit
                    }

                    Label {
                        id: labelTitle
                        color: "#cad1d6"
                        text: qsTr("Domino Bot Path Setter")
                        anchors.left: image.right
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        verticalAlignment: Text.AlignVCenter
                        anchors.topMargin: 0
                        anchors.leftMargin: 5
                    }
                }

                Row {
                    id: rowBtns
                    x: 923
                    width: 105
                    height: 35
                    anchors.right: parent.right
                    anchors.top: parent.top

                    TopBarBtn {
                        id: btnMinimize
                    }

                    TopBarBtn {
                        id: btnMaximzie
                        btnIconSource: "../img/svg/maximize_icon.svg"
                    }

                    TopBarBtn {
                        id: btnClose
                        btnColorClicked: "#c2175e"
                        btnIconSource: "../img/svg/close_icon.svg"
                    }
                }
            }

            Rectangle {
                id: content
                color: "#00000000"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: topBar.bottom
                anchors.bottom: parent.bottom
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0

                Rectangle {
                    id: sidieBar
                    width: 70
                    color: "#1a1d23"
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom

                    Column {
                        id: column
                        anchors.fill: parent
                        anchors.bottomMargin: 183

                        Button {
                            id: button
                            width: 70
                            text: qsTr("Button")
                        }
                    }
                }

                Rectangle {
                    id: contentPages
                    color: "#00000000"
                    anchors.left: sidieBar.right
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25
                    anchors.leftMargin: 0
                }

                Rectangle {
                    id: bottomBar
                    color: "#1a1d23"
                    anchors.left: sidieBar.right
                    anchors.right: parent.right
                    anchors.top: contentPages.bottom
                    anchors.bottom: parent.bottom
                    anchors.topMargin: 0
                    anchors.leftMargin: 0

                    Label {
                        id: labelBottominfo
                        color: "#9eaab2"
                        text: qsTr("App description")
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 30
                        anchors.leftMargin: 10
                    }
                }
            }
        }
    }
}
