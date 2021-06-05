import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Button {
    id: btnLeftMenu
    text: qsTr("Home")

    property url btnIconSource: "../../img/svg/home_icon.svg"
    property color btnColorDefault: "#1c1d20"
    property color btnColorHovered: "#23272E"
    property color btnColorClicked: "#00a1f1"
    property color activeMenuColorLeft: "#55aaff"
    property color activeMenuColorRight: "#2c313c"
    property int iconWidth: 18
    property int iconHeight: 18
    property bool isActiveMenu: true

    // function holder object
    QtObject {
        id: internal

        property var dynamicColor: if (btnLeftMenu.down) {
                                       btnColorClicked
                                   } else if (btnLeftMenu.hovered) {
                                       btnColorHovered
                                   } else {
                                       btnColorDefault
                                   }
    }

    implicitWidth: 250
    implicitHeight: 60

    background: Rectangle {
        id: bgBtn
        color: internal.dynamicColor

        // active highlight left
        Rectangle {
            anchors {
                top: parent.top
                left: parent.left
                bottom: parent.bottom
            }
            color: activeMenuColorLeft
            width: 3
            visible: isActiveMenu
        }

        // active highlight right
        Rectangle {
            anchors {
                top: parent.top
                right: parent.right
                bottom: parent.bottom
            }
            color: activeMenuColorRight
            width: 5
            visible: isActiveMenu
        }
    }

    contentItem: Item {
        id: content
        anchors.fill: parent

        Image {
            id: iconBtn
            source: btnIconSource
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 26
            sourceSize.width: iconWidth
            sourceSize.height: iconHeight
            width: iconWidth
            height: iconHeight
            fillMode: Image.PreserveAspectFit
            visible: false
            antialiasing: true
        }

        // change the color of the svg icon
        ColorOverlay {
            anchors.fill: iconBtn
            source: iconBtn
            color: "#ffffff"
            anchors.verticalCenter: parent.verticalCenter
            antialiasing: true
            width: iconWidth
            height: iconHeight
        }

        Text {
            color: "#ffffff"
            text: btnLeftMenu.text
            font: btnLeftMenu.font
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 75
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:60;width:250}
}
##^##*/

