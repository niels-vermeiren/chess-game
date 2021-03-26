import QtQuick 2.11

Rectangle {
    id: square;
    width: 70;
    height: 70
    color: squareColour
    property int row: Math.floor(index/8);
    property int col: index % 8;
    property string squareColour: BoardModel ? BoardModel.squares[row][col].squareColour : ""
    property string pieceColour: BoardModel ?  BoardModel.squares[row][col].piece.pieceColour : ""

    function movePiece() {
        var activePieceCol = col;
        if (BoardModel && posMoveRect.visible) {
            activePieceCol = checkMakeCastlingMove();
            BoardModel.squares[boardRepeater.activePieceRow][boardRepeater.activePieceCol].changePiece("", "", false);
            BoardModel.squares[row][col].changePiece(boardRepeater.activePiece, boardRepeater.activePieceColour, true);
            boardRepeater.activePieceCol = activePieceCol;
            boardRepeater.activePieceRow = row;
        }
        boardRepeater.checkForCheck();
        boardRepeater.pieceHasReachedEnd();
        boardRepeater.clearPosMoves();
        BoardModel.makeAIMove();
    }

    function checkMakeCastlingMove () {
        var activePieceCol = col;
        //Check for castle move
        if(boardRepeater.activePiece === "♚") {
            //Check which rook the king is castling to
            if(boardRepeater.activePieceCol - 2 == col) {
                //Move rook to the right side of king
                BoardModel.squares[boardRepeater.activePieceRow][0].changePiece("", "", false);
                BoardModel.squares[row][2].changePiece("♜", boardRepeater.activePieceColour, true);
                activePieceCol = 2;
            } else if (boardRepeater.activePieceCol + 2 == col) {
                BoardModel.squares[boardRepeater.activePieceRow][7].changePiece("", "", false);
                BoardModel.squares[row][4].changePiece("♜", boardRepeater.activePieceColour, true);
                activePieceCol = 4;
            }
        }
        return activePieceCol;
    }

    function getPossibleMoves() {       
        if(!BoardModel || boardRepeater.gameHasEnded || BoardModel.squares[row][col].piece.pieceColour === "black") return;
        var posMoves =  BoardModel.clickedOnPiece(row, col);
        if (!posMoves[0]) boardRepeater.clearPosMoves();

        for (var i=0; i!== posMoves.count ; i++) {
            if(!posMoves[i]) break;
            var index = posMoves[i][0] * 8 + posMoves[i][1];
            if (i === 0) boardRepeater.clearPosMoves();
            boardRepeater.activePieceRow = row;
            boardRepeater.activePieceCol = col;
            if(BoardModel.squares[row][col].piece && BoardModel.squares[row][col].piece.pieceColour) {
                boardRepeater.activePieceColour = BoardModel.squares[row][col].piece.pieceColour;
                boardRepeater.activePiece = BoardModel.squares[row][col].piece.piece;
                boardRepeater.itemAt(index).children[1].visible = true;
            }
        }
    }

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
        opacity: 0.4
        z: 100
        MouseArea {
            z: 100
             propagateComposedEvents: true
             anchors.fill: parent
             hoverEnabled: true
             onEntered: parent.opacity = 0.8
             onExited: parent.opacity = 0.4
             onClicked: square.movePiece()
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
        onClicked: square.getPossibleMoves();
    }
}
