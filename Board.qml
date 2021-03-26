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
        id: board

        //Piece Chooser
        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            z: 99;
            Row {
                anchors.verticalCenter: parent.verticalCenter
                id: pieceChooser
                x: ((8*73-3)/2) - 100
                visible: false
                property var pieces: ["♛", "♞", "♜", "♝"]
                Repeater {
                    model: 4
                    Rectangle {
                        color: "#013b6c"
                        width: 50
                        height: 50
                        x: 50
                        anchors.verticalCenter: parent.verticalCenter
                        z: 102
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            id: pieceChooserTxt
                            text: pieceChooser.pieces[index]
                            color: "white"
                            font.pointSize: 30
                        }
                        MouseArea {
                             anchors.fill: parent
                             hoverEnabled: true
                             onEntered: pieceChooserTxt.color = "black"
                             onExited: pieceChooserTxt.color = "white"
                             onClicked: {
                                BoardModel.squares[boardRepeater.activePieceRow][boardRepeater.activePieceCol]
                                 .changePiece(pieceChooserTxt.text, boardRepeater.activePieceColour, true);
                                 boardRepeater.checkForCheck();
                                 pieceChooser.visible = false;
                             }
                         }
                    }
                }
            }
        }

        //Chess squares
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
                property bool isCheckBlack: false
                property bool isCheckMateBlack: false
                property bool isCheckWhite: false
                property bool isCheckMateWhite: false
                property bool gameHasEnded: false
                property bool isStaleMate: false
                property bool pieceChooserIsVisible: false

                function resetGame() {
                    isCheckBlack = false;
                    isCheckMateBlack = false;
                    isCheckWhite = false;
                    isCheckMateWhite = false;
                    gameHasEnded = false;
                    isStaleMate = false;
                    clearPosMoves();
                    BoardModel.newGame();
                }
                model: 64
                id: boardRepeater

                function clearPosMoves () {
                    for (var i=0; i!== boardRepeater.count ; i++) boardRepeater.itemAt(i).children[1].visible = false;
                }

                function pieceHasReachedEnd () {
                    //If a pawn has reached the end of the board, show the pieceChooser, replace pawn with chosen piece
                    if(activePiece === "♟" && activePieceColour == "white" && activePieceRow === 0) {
                        pieceChooser.visible = true;
                    }
                }

                function checkForCheck() {
                    isCheckBlack = BoardModel.isCheckForColour("black");
                    if (isCheckBlack) isCheckMateBlack = BoardModel.isCheckMateForColour("black");
                    isCheckWhite = BoardModel.isCheckForColour("white");
                    if (isCheckWhite) isCheckMateWhite = BoardModel.isCheckMateForColour("white");
                    if(!isCheckBlack && !isCheckWhite) isStaleMate = BoardModel.isStaleMate();
                    //Check game has ended
                    if(isCheckMateBlack || isCheckMateWhite) {
                        gameHasEnded = true;
                        clearPosMoves();
                    }
                }
                Square {}
            }
        }
        Components.Sidebar {}
     }
 }
