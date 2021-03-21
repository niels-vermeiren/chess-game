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
                property bool whiteTurn: true
                property bool isCheckBlack: false
                property bool isCheckMateBlack: false
                property bool isCheckWhite: false
                property bool isCheckMateWhite: false
                property bool gameHasEnded: false

                function resetGame() {
                    whiteTurn = true;
                    isCheckBlack = false;
                    isCheckMateBlack = false;
                    isCheckWhite = false;
                    isCheckMateWhite = false;
                    gameHasEnded = false;
                    clearPosMoves();
                    BoardModel.newGame();
                }

                model: 64
                id: boardRepeater
                function clearPosMoves () {
                    for (var i=0; i!== boardRepeater.count ; i++) boardRepeater.itemAt(i).children[1].visible = false;
                }
                function checkForCheck() {
                    isCheckBlack = BoardModel.isCheckForColour("black");
                    if (isCheckBlack) isCheckMateBlack = BoardModel.isCheckMateForColour("black");

                    isCheckWhite = BoardModel.isCheckForColour("white");
                    if (isCheckWhite) isCheckMateWhite = BoardModel.isCheckMateForColour("white");
                }

                Square {}
            }
        }
        Components.Sidebar {}
     }
 }
