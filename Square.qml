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
        if (BoardModel && posMoveRect.visible) {
            boardRepeater.whiteTurn = !boardRepeater.whiteTurn;
            BoardModel.squares[boardRepeater.activePieceRow][boardRepeater.activePieceCol].changePiece("", "");
            BoardModel.squares[row][col].changePiece(boardRepeater.activePiece, boardRepeater.activePieceColour);
            boardRepeater.checkForCheck();
        }
        boardRepeater.clearPosMoves();
    }

    function getPossibleMoves() {
        if(BoardModel) {
            if(BoardModel.squares[row][col].piece.pieceColour !== "" && (boardRepeater.whiteTurn && BoardModel.squares[row][col].piece.pieceColour !== "white")
                    || (!boardRepeater.whiteTurn && BoardModel.squares[row][col].piece.pieceColour !== "black")) return;

            var posMoves =  BoardModel.clickedOnPiece(row, col);
            if (!posMoves[0]) boardRepeater.clearPosMoves();

            for (var i=0; i!== posMoves.count ; i++) {
                if(!posMoves[i]) break;
                var index = posMoves[i][0] * 8 + posMoves[i][1];

                if (i === 0) boardRepeater.clearPosMoves();
                boardRepeater.activePieceRow = row;
                boardRepeater.activePieceCol = col;
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