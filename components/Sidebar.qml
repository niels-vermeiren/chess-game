import QtQuick 2.0

Item {
    Rectangle {
        x: 8 * 73;
        width: 200;
        height: 8*73-3;
        color: "#111212"

        Rectangle {
            width: 100;
            height: 50;
            color: "orange"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Text {
                text: "Move piece"
                color: "black";
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea {
                 anchors.fill: parent
                 hoverEnabled: true
                 onEntered: parent.color = "yellow"
                 onExited: parent.color = "orange"
                 onPressed: parent.opacity = 0.8
                 onReleased: parent.opacity = 1.0
                 onClicked: {
                     BoardModel.squares[6][3].changePiece("", "");
                     BoardModel.squares[4][3].changePiece("♟", "white");
                 }
            }
        }
     }
}
