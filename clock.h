#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QDateTime>

class QTimer;
class Clock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDateTime now READ now NOTIFY nowChanged)
public:
    explicit Clock(QObject *parent=0);

    const QDateTime& now() const { return m_now; }

signals:
    void nowChanged();

private:
    QTimer *m_timer;
    QDateTime m_now;
};

#endif // CLOCK_H
