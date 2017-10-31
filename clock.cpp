#include <QTimer>
#include <QDateTime>
#include "clock.h"

Clock::Clock(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [this]() {
        qDebug("TICKING");

        m_now = QDateTime::currentDateTime();
        emit nowChanged();
    });

    m_timer->start(1000);
}
