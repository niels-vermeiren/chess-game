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
                property int activePieceRow: -1
                property int activePieceCol: -1
                property string activePiece: ""
                property string activePieceColour: ""

                model: 64
                id: boardRepeater
                function clearPosMoves () {
                    for (var i=0; i!== boardRepeater.count ; i++) {
                        boardRepeater.itemAt(i).children[1].visible = false;
                    }
                }

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

                   Rectangle {
                        id: posMoveRect
                        visible: false
                        anchors.centerIn: parent
                        width: 40
                        height: 40
                        color: "white"
                        radius: 40
                        opacity: 0.5
                        z: 100
                        MouseArea {
                             anchors.fill: parent
                             hoverEnabled: true
                             onEntered: parent.opacity = 0.8
                             onExited: parent.opacity = 0.5
                             onClicked: {
                                 mouse.accepted = false
                                 if (BoardModel && posMoveRect.visible) {
                                     BoardModel.squares[boardRepeater.activePieceRow][boardRepeater.activePieceCol].changePiece("", "");
                                     BoardModel.squares[row][col].changePiece(boardRepeater.activePiece, boardRepeater.activePieceColour);
                                 }
                                 boardRepeater.clearPosMoves();
                             }
                         }

                   }

                   MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.color = "#3ec73a"

                        propagateComposedEvents: true
                        z: 99
                        onExited: parent.color = parent.squareColour
                        onPressed: parent.opacity = 0.8
                        onReleased: parent.opacity = 1.0
                        onClicked: {
                            if(BoardModel) {
                                var posMoves =  BoardModel.clickedOnPiece(row, col);




                                if (!posMoves[0]) {
                                    boardRepeater.clearPosMoves();
                                    return;
                                }

                                var index = posMoves[0][0] * 8 + posMoves[0][1];
                                if(boardRepeater.itemAt(index).children[1].visible) {

                                    boardRepeater.clearPosMoves();
                                } else {
                                    boardRepeater.clearPosMoves();
                                    boardRepeater.activePieceRow = row;
                                    boardRepeater.activePieceCol = col;
                                    boardRepeater.activePieceColour = BoardModel.squares[row][col].piece.pieceColour;
                                    boardRepeater.activePiece = BoardModel.squares[row][col].piece.piece;
                                    boardRepeater.itemAt(index).children[1].visible = true;
                                }
                            }
                        }
                   }
                }
            }
        }

        Components.Sidebar {}
     }
 }
