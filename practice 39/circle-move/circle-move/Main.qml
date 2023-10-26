import QtQuick
import QtQuick.Window

Window {
    id: root
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: qsTr("Moving circle")

    Rectangle{
        id: scene
        anchors.fill: parent
        state: "InitialState"
        Rectangle{
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 3

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    scene.state = "MovingState";
                    ball.x += (rightRectangle.x - leftRectangle.x) / 10;
                    if(ball.x >= rightRectangle.x)
                    {
                        scene.state = "InitialState";
                    }
                }
            }

            Text {
                anchors.centerIn: parent
                text: "move"
            }
        }

        Rectangle{
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 3

            MouseArea{
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }

            Text {
                anchors.centerIn: parent
                text: "return"
            }
        }

        Rectangle{
            id: ball
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            color: "darkgreen"
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width / 2
        }

        states: [
            State{
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            },
            State{
                name: "MovingState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
            Transition {
                from: "MovingState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x, y"
                    duration: 500
                    easing.type: Easing.InExpo
                }
            }
        ]
    }
}
