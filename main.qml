import QtQuick 2.12
import QtQuick.Window 2.12
import "components" as Components

Window {
    id: window
    visible: true
    width: 8*73 + 200
    height: 8*73-3

    Rectangle {
        width: 8*73;
        height: 8*73-3;
        color: "black"

        Grid {
            id: grid;
            rows: 8;
            columns: 8;
            spacing: 3;

            Repeater {
                model: 64

                Rectangle {
                    id: square;
                    property int row: Math.floor(index/8);
                    property int col: index % 8;
                    property string squareColour: BoardModel ? BoardModel.squares[row][col].squareColour : ""
                    property string pieceColour: BoardModel ?  BoardModel.squares[row][col].piece.pieceColour : ""
                    width: 70;
                    height: 70
                    color: squareColour
                    Text {
                        id: txt
                        text:  BoardModel && BoardModel.squares[row][col].piece
                               && BoardModel.squares[row][col].piece.piece ? BoardModel.squares[row][col].piece.piece  : ""
                        color: parent.pieceColour
                        font.pointSize: 30
                        anchors.centerIn: parent
                   }

                   MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.color = "#3ec73a"
                        onExited: parent.color = parent.squareColour
                        onPressed: parent.opacity = 0.8
                        onReleased: parent.opacity = 1.0
                   }
                }
            }
        }

        Components.Sidebar {}
     }
 }
