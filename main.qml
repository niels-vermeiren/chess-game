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
                        if(gameBoard != null) color = gameBoard.getSquareColourAt(row, col);
                        return color;
                    }
                    property string pieceColour: {
                        var color = "";
                        if(gameBoard != null) color = gameBoard.getPieceColourAt(row, col);
                        return color;
                    }
                    width: 70;
                    height: 70
                    color: squareColour
                    Text {
                        id: txt
                        text:  {
                            var p = "";
                            if(gameBoard != null) p = gameBoard.getPieceAt(row, col);
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
                color: "green"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    text: "Move piece"
                    color: "white";
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

            }
            Text {
                text: "ex. 2way binding text btn"
                color: "white";
                anchors.horizontalCenter: parent.horizontalCenter
                y: 25
            }

            Rectangle {
                width: 200;
                height: 50;
                anchors.horizontalCenter: parent.horizontalCenter
                y: 50;
                color: "orange"
                Text {
                        id: biDirectional

                        text: MyModel.myValue
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                }
                Binding {
                        target: MyModel
                        property: "myValue"
                        value: biDirectional.text
                }
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                         onClicked: MyModel.myValue = "Hello Werellld"
                }
            }
            Text {
                text: "ex. 2way binding square piece"
                color: "white";
                anchors.horizontalCenter: parent.horizontalCenter
                y: 130
            }

            Rectangle {

                anchors.horizontalCenter: parent.horizontalCenter
                y: 155;
                id:birect
                width: 70;
                height: 70
                color: MySquareModel.square.squareColour;
                Text {
                    id: birecttxt
                    text: MySquareModel.square.piece.piece
                    font.pointSize: 30
                    anchors.centerIn: parent
               }

               MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = "#3ec73a"
                    onExited:  parent.color = MySquareModel.square.squareColour
                    //onExited: parent.color = parent.squareColour
                    onPressed: parent.opacity = 0.8
                    onReleased: parent.opacity = 1.0
                }
             /* Binding {
                       target: MySquareModel.square[index]
                       property: "squareColour"
                       value: birect.colour
               }
              Binding {
                       target: MySquareModel.square.piece
                       property: "piece"
                       value: birecttxt.text
               }*/
               MouseArea {
                   anchors.fill: parent
                   onClicked: {
                      MySquareModel.square.setSquareColour("yellow");
                      MySquareModel.square.setPiez("♜", "black");

                                         }
               }
            }
        }
        }


    }



