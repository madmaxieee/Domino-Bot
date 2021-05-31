import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Button {
    id: btnMinimize

    property url btnIconSource: "../../img/svg/minimize_icon.svg"
    property color btnColorDefault: "#1c1d20"
    property color btnColorHovered: "#23272E"
    property color btnColorClicked: "#00a1f1"

    // function holder object
    QtObject {
        id: internal

        property var dynamicColor: if (btnMinimize.down) {
                                       btnColorClicked
                                   } else if (btnMinimize.hovered) {
                                       btnColorHovered
                                   } else {
                                       btnColorDefault
                                   }
    }

    implicitWidth: 35
    implicitHeight: 35

    background: Rectangle {
        id: bgBtn
        color: internal.dynamicColor

        Image {
            id: iconBtn
            source: btnIconSource
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            height: 16
            width: 16
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
