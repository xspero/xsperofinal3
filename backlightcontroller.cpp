#include <QFile>
#include <QTextStream>
#include <QDebug>
//#include <serialisimo.h>
#include <backlightcontroller.h>


namespace {
void writeBacklightFile(bool isOn)
{
    QFile backlightFile("/sys/class/backlight/rpi_backlight/bl_power");

    if (backlightFile.exists()) {
        if (!backlightFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Can't open backlightfile for write?";
            return;
        }
        QTextStream out(&backlightFile);
        out << (isOn ? 0 : 1);
    } else {
        qDebug() << "Backlight would have been turned " << (isOn ? "on" : "off") << " here";
    }
}

}

BacklightController::BacklightController(QObject *parent) : QObject(parent)
{
}



void BacklightController::backlightOn()
{
    setValue(1);


    if (!m_on) {
        writeBacklightFile(true);


    }

    m_countdown = 60;
    m_on = true;

}

void BacklightController::backlightCountdown()
{

    if (m_on) {
        if (m_countdown == 0) {
            writeBacklightFile(false);
            setValue(0);
            m_on = false;
        } else {
            m_countdown -= 1;

        }
    }
    qDebug() << "la cuenta va en " << m_countdown;
}
