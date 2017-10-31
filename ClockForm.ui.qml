import QtQuick 2.7

Rectangle {
    property alias date: dateText.text
    property alias time: timeText.text
    property alias day: dayText.text

    width: 500
    height: 150
    color: "#00000000"
    radius: 1
    border.color: "#00000000"
    border.width: 3
    anchors.topMargin: 103
    anchors.leftMargin: 236
    anchors.left: parent.left
    anchors.top: parent.top

    Text {
        id: dateText
        color: "#3a80a5"
        text: "2016-04-06"
        anchors.horizontalCenterOffset: -126
        anchors.topMargin: 83
        //font.family: mainFont.name
        font.pixelSize: 36
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: timeText
        x: 39
        y: 37
        color: "#004279"
        text: "19:49"
        anchors.verticalCenterOffset: 0
        //font.family: mainFont.name
        font.pixelSize: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 115
        anchors.horizontalCenter: parent.horizontalCenter
        wrapMode: Text.WordWrap
    }

    Text {
        id: dayText
        y: 23

        color: "#3a80a5"
        text: "Wednesday"
        anchors.horizontalCenterOffset: -126
        anchors.bottomMargin: 73
        //font.family: mainFont.name
        font.pixelSize: 45
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
