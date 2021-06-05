import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Item {
    id: item1
    Rectangle {
        id: rectangle
        color: "#2c313c"
        anchors.right: parent.right
        anchors.fill: parent

        Label {
            x: 302
            y: 137
            width: 179
            height: 76
            color: "#ffffff"
            text: qsTr("Editting Page")
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Tahoma"
            font.pointSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
            visible: false
        }

        Rectangle {
            id: workSpace
            color: "#00000000"
            border.color: "#3494cb"
            anchors.left: toolBar.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10

            Image {
                id: edittingSVG
                source: "../../img/svg/example.svg"
                sourceSize.width: 1920
                sourceSize.height: 1080
                fillMode: Image.PreserveAspectFit
                visible: false
                anchors.fill: parent
            }

            // change the color of the svg
            ColorOverlay {
                anchors.fill: edittingSVG
                source: edittingSVG
                color: "#ffffff"
                antialiasing: true
            }
        }

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

                Button {
                    id: button
                    text: qsTr("Button")
                }

                Button {
                    id: button1
                    text: qsTr("Button")
                }

                Button {
                    id: button2
                    text: qsTr("Button")
                }

                Button {
                    id: button3
                    text: qsTr("Button")
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:800}D{i:4}
}
##^##*/

