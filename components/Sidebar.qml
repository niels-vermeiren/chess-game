import QtQuick 2.11

Item {
    Rectangle {
        x: 8 * 73
        width: 200
        height: 8*73-3
        color: "#111212"

        Rectangle {
            id: newGameBtn
            width: 100;
            height: 50;
            color: "#d52032"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Text {
                id: txtBtn
                text: qsTr("New Game")
                color: "white";
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }

            MouseArea {
                 anchors.fill: parent
                 hoverEnabled: true
                 onEntered: {
                     parent.color = "yellow"
                     txtBtn.color = "black"
                 }
                 onExited: {
                     parent.color = "#d52032"
                     txtBtn.color = "white"
                 }
                 onPressed: parent.opacity = 0.8
                 onReleased: parent.opacity = 1.0
                 onClicked: boardRepeater.resetGame();
            }
        }
        Text {
            id: isCheckBlack
            text: boardRepeater.isCheckBlack ? boardRepeater.isCheckMateBlack ? "CheckMate!" : "Check" : ""
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 200
            font.bold: true
        }
        Text {
            id: isCheckWhite
            text: boardRepeater.isCheckWhite ? boardRepeater.isCheckMateWhite ? "CheckMate!" : "Check" : ""
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 368
            font.bold: true
        }
     }
}
