import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4

Item {
    Rectangle {
        x: 8 * 73;
        width: 200;
        height: 8*73-3;
        color: "#111212"

        Rectangle {
            width: 100;
            height: 50;
            color: "#d52032"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: txtBtn
                text: "New Game"
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
                 onClicked: BoardModel.newGame();
            }
        }
     }
}
