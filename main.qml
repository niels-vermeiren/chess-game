import QtQuick 2.12
import QtQuick.Window 2.12


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
                    property string squareColour: {
                        var color = "";
                        if(BoardModel != null) color = BoardModel.squares[row][col].squareColour
                        return color;
                    }
                    property string pieceColour: {
                        var color = "";
                        if(BoardModel != null) color = BoardModel.squares[row][col].piece.pieceColour;
                        return color;
                    }
                    width: 70;
                    height: 70
                    color: squareColour
                    Text {
                        id: txt
                        text:  {
                            var p = "";
                            if(BoardModel != null && BoardModel.squares[row][col].piece !== undefined
                                    &&  BoardModel.squares[row][col].piece.piece !== undefined) {
                                p = BoardModel.squares[row][col].piece.piece;
                            }
                            return p;
                        }
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
                         BoardModel.squares[6][3].setPiez("", "");
                         BoardModel.squares[4][3].setPiez("♟", "white");
                     }
                }
            }
         }
     }
 }






