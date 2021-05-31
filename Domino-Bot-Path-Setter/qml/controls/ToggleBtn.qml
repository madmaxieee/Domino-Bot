import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Button {
    id: btnToggle

    property url btnIconSource: "../../img/svg/menu_icon.svg"
    property color btnColorDefault: "#1c1d20"
    property color btnColorHovered: "#23272E"
    property color btnColorClicked: "#00a1f1"

    // function holder object
    QtObject {
        id: internal

        property var dynamicColor: if (btnToggle.down) {
                                       btnColorClicked
                                   } else if (btnToggle.hovered) {
                                       btnColorHovered
                                   } else {
                                       btnColorDefault
                                   }
    }

    implicitWidth: 70
    implicitHeight: 60

    background: Rectangle {
        id: bgBtn
        color: internal.dynamicColor

        Image {
            id: iconBtn
            source: btnIconSource
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            height: 25
            width: 25
            fillMode: Image.PreserveAspectFit
            visible: false
        }

        // change the color of the svg icon
        ColorOverlay {
            anchors.fill: iconBtn
            source: iconBtn
            color: "#ffffff"
            antialiasing: false
        }
    }
}
