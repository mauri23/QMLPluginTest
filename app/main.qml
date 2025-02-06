import QtQuick 2.15
import QtQuick.Controls
import MyWonderfulPlugin 1.0

ApplicationWindow{
    visible: true

    width: 360
    height: 360

    MyWonderfulItem {
        anchors.centerIn: parent
    }

    MyWonderfulComponent
    {
        width: 100
        height: 100
        anchors.bottom: parent.bottom
    }
}
