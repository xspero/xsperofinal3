import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0



ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")



    //signal userNameChanged()
    signal activateScreen()








    //MouseEvent



    MouseArea {
        anchors.rightMargin: 0
        anchors.bottomMargin: -6
        anchors.leftMargin: 0
        anchors.topMargin: 6
        anchors.fill: parent

        //onClicked:
    }


    /*TabBar {
        id: bar
        width: parent.width
        height: 100

        TabButton {
            height: 100//parent.height
            //text: qsTr("Home")
            Image {
                id: xsperologo
                x: 8
                y: 8
                source: "res/logo.png"
            }

        }


    } */


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page2 {
        }
        Page1 {
        }
        Page3 {
        }


    }


    footer:TabBar {



        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {onPressed: activateScreen()
            text: qsTr("Escenas")
            /*Image {
                id: personalizaricon
                x: 40
                y: 8
                source: "res/icons (3).png"
                height: 30
                width:30
            }*/
        }
        TabButton {onPressed: activateScreen()
            text: qsTr("Personalizar")
            /*Image {
                id: escenasicon
                x: 40
                y: 8
                source: "res/icons (2).png"
                height: 30
                width:30
            }*/
        }
        TabButton {onPressed: activateScreen()
            text: qsTr("Seguridad")
            /*Image {
                id: seguridadicon
                x: 40
                y: 8
                source: "res/icons (1).png"
                height: 30
                width:30
            }*/
        }
    }



    //hehe

}
