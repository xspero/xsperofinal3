#ifndef SCRIPTLAUNCHER_H
#define SCRIPTLAUNCHER_H

#include <QObject>
#include <QProcess>

class ScriptLauncher : public QObject
{

Q_OBJECT
public:
explicit ScriptLauncher(QObject *parent = 0);

Q_INVOKABLE void launchScript();
Q_INVOKABLE void apagarPantalla();
Q_INVOKABLE void encenderPantalla();
//Q_INVOKABLE QString program = "./path/to/Qt/examples/widgets/analogclock";

private:
QProcess *m_process;
};

#endif // SCRIPTLAUNCHER_H
