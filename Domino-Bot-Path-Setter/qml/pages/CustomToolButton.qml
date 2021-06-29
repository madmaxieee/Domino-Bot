import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Button {
    id: button

    // Custom Properties
    property color colorDefault: "#4891D9"
    property color colorMouseOver: "#3f7ebd"
    property color colorActive: "#55aaff"
    property string displayText: "Button"
    property bool isActive: false

    QtObject {
        id: internal

        property var dynamicColor: if (button.isActive) {
                                       colorActive
                                   } else if (button.down) {
                                       button.down ? colorActive : colorDefault
                                   } else {
                                       button.hovered ? colorMouseOver : colorDefault
                                   }
    }

    text: qsTr(displayText)
    contentItem: Item {
        Text {
            id: name
            text: button.text
            font: button.font
            color: "#ffffff"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    background: Rectangle {
        color: internal.dynamicColor
        radius: 10
    }
}
/*##^##
Designer {
    D{i:0;autoSize:true;height:40;width:200}
}
##^##*/

