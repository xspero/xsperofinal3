#include "scriptlauncher.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ScriptLauncher::ScriptLauncher(QObject *parent) :
QObject(parent),
m_process(new QProcess(this))
{

}

void ScriptLauncher::launchScript()
{

}



//*APAGAR Y PRENDER PANTALLA**//

void ScriptLauncher::apagarPantalla()
{
    bool isOn=false;

    QFile backlightFile("/sys/class/backlight/rpi_backlight/bl_power");

    if (backlightFile.exists()) {
        if (!backlightFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            //qWarning() << "Can't open backlightfile for write?";
            return;
        }
        QTextStream out(&backlightFile);
        out << (isOn ? 0 : 1);
    } else {
        qDebug() << "Backlight would have been turned " << (isOn ? "on" : "off") << " here";
        qDebug() << "apagarpantalla() en scriptlauncher.cpp";
    }


}

void ScriptLauncher::encenderPantalla()
{
    bool isOn=true;

    QFile backlightFile("/sys/class/backlight/rpi_backlight/bl_power");

    if (backlightFile.exists()) {
        if (!backlightFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            //qWarning() << "Can't open backlightfile for write?";
            return;
        }
        QTextStream out(&backlightFile);
        out << (isOn ? 0 : 1);
    } else {
        qDebug() << "Backlight would have been turned " << (isOn ? "on" : "off") << " here";
    }


}
