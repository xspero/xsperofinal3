#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQml>
#include <serialisimo.h>
#include <clock.h>
#include <backlightcontroller.h>
#include <QtQml/QQmlContext>
#include <serialisimo.h>
#include <backlightcontroller.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    //QScopedPointer<Serialisimo> serialon(new Serialisimo);

    QQmlApplicationEngine engine;

    Clock clock(&engine);
    BacklightController estadopantalla(&engine);
    BacklightController blCtrl(&engine);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    Serialisimo miSerial;
    engine.rootContext()->setContextProperty("serialito",&miSerial);




    QObject *rootObject = engine.rootObjects().first();



    qDebug() << "root: " << rootObject;


    //holi
    engine.rootContext()->setContextProperty("clock", &clock);





    engine.rootContext()->setContextProperty("estadopantalla", &estadopantalla);



    engine.connect(&clock, &Clock::nowChanged,
                   &blCtrl, &BacklightController::backlightCountdown);

    engine.connect(rootObject, SIGNAL(activateScreen()),        //cuando en rootObject yo emita la Señal activatescreen
                &blCtrl, SLOT(backlightOn()));                  //en el objeto blCtrl se activara el slot backlightOn


    //holi




    return app.exec();
}
