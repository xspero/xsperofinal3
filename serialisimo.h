#ifndef SERIALISIMO_H
#define SERIALISIMO_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QColorDialog>
#include <QMediaPlayer>

class Serialisimo : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(qreal valor READ  valor WRITE setvalor NOTIFY valuechanged)
    //Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
    //Q_PROPERTY(qreal valordimmer READ valordimmer WRITE setvalor)

public:

    explicit Serialisimo(QObject *parent = 0);

    Q_INVOKABLE int pantallaencendida=1;
    Q_INVOKABLE int vistaprevia;
    Q_INVOKABLE int numescena;  //variable global para numero de escena
    Q_INVOKABLE void test();
    Q_INVOKABLE void guardar(int escena);//, QString color, int cto, int estado);
    Q_INVOKABLE void restablecer();

/*  //ESCENAS //RGB,Foco1,Foco2,Cortina,Dimmer
    Q_INVOKABLE QString escena1[5]={"#ff0000","0","1","1","15"};//RGB,Foco1,Foco2,Cortina,Dimmer
    Q_INVOKABLE QString escena2[5]={"#0000ff","1","0","0","50"};//RGB,Foco1,Foco2,Cortina,Dimmer
    Q_INVOKABLE QString escena3[5]={"#000000","0","0","0","00"};//RGB,Foco1,Foco2,Cortina,Dimmer

*/


    //FOCOS
    Q_INVOKABLE QString foco1[4]={"0","1","0","0"};
    Q_INVOKABLE void setfoco1(int numero);  //# de color en el arreglo, debe retornar valor
    Q_INVOKABLE int recuperarfoco1(int numescena); //para usarlo en QML

    Q_INVOKABLE QString foco2[4]={"0","1","0","0"};
    Q_INVOKABLE void setfoco2(int numero);  //# de color en el arreglo
    Q_INVOKABLE int recuperarfoco2(int numescena); //para usarlo en QML

    //para el RGB
    Q_INVOKABLE QString colorRGB[4]={"#ff0000","#ff0000","#0000ff","#000000"}; //se almacenan las escenas
    Q_INVOKABLE QString getcolorRGB(int numero);  //color en el arreglo, debe retornar valor
    Q_INVOKABLE QString recuperarcolor();//para utilizarlo en QML

    Q_INVOKABLE QString obtenercolor(QString color);  //para guardar color anterior/apagado
    Q_INVOKABLE QString coloranterior; //almacena el color anterior

    //para CORTINA
    Q_INVOKABLE QString cortina[4]={"0","1","0","0"};
    Q_INVOKABLE void setcortina(int numero);  //# de color en el arreglo, debe retornar valor
    Q_INVOKABLE int recuperarcortina(int numescena); //para usarlo en QML

    Q_INVOKABLE QString dimmer[4]={"0","100","50","0"};
    Q_INVOKABLE void setdimmer(int numero);  //# de color en el arreglo, debe retornar valor
    Q_INVOKABLE int recuperardimmer(int numescena); //para usarlo en QML


    //COMANDOS ENVIAR
    Q_INVOKABLE void enviarfoco(int cto,int estado);
    Q_INVOKABLE void enviarcortina(int cto,int estado);
    Q_INVOKABLE void enviardimmer(int numero);
    Q_INVOKABLE void enviarRGB(QString color);


    //Botones 2da pagina
    Q_INVOKABLE void apagartodo();
    Q_INVOKABLE void proyeccion();
    Q_INVOKABLE void escenaclases();



    int getPantallaencendida() const;
    void setPantallaencendida(int value);

signals:
    //qreal valueChanged(int valor);

};



#endif // SERIALISIMO_H
