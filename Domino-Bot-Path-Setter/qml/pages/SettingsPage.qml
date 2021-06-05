import QtQuick 2.15
import QtQuick.Controls 2.15

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
            text: qsTr("Settings Page")
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Tahoma"
            font.pointSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:800}
}
##^##*/

