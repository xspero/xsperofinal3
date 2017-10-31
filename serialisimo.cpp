#include <serialisimo.h>
#include <QtSerialPort/QSerialPort>
#include <QtWidgets/QSlider>
#include <QColor>
QSerialPort *serial;
int i=0;

Serialisimo::Serialisimo(QObject *parent) : QObject(parent)
{

    if (i==0)
    {
        serial = new QSerialPort(this);
        serial = new QSerialPort(this);
        serial->setPortName("/dev/ttyAMA0");
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);
        qDebug()<<"serial iniciado";
        i=1;
    }

}



void Serialisimo::test()
{
    //enviarRGB("#ffffff");
    //qDebug()<< "color guardado"<<coloranterior;
    qDebug()<< "Holi, soy C++";
    qDebug()<<"escena numero "<<numescena;
    qDebug()<<"colorRGB[1]"<<colorRGB[1];
    qDebug()<<"colorRGB[2]"<<colorRGB[2];
    qDebug()<<"colorRGB[3]"<<colorRGB[3];
    //qDebug()<<foco1[numescena];
    //qDebug()<<estadofoco1[numescena];
}

void Serialisimo::restablecer()
{
    QString bfoco1[4]={"0","1","0","0"};
    QString bfoco2[4]={"0","1","0","0"};
    QString bcolorRGB[4]={"#ff0000","#ff0000","#0000ff","#000000"}; //se almacenan las escenas
    QString bcortina[4]={"0","1","0","0"};
    QString bdimmer[4]={"0","100","50","0"};

    for(int n=0;n<4;n++)
    {
        foco1[n]=bfoco1[n];
        foco2[n]=bfoco2[n];
        colorRGB[n]=bcolorRGB[n];
        cortina[n]=bcortina[n];
        dimmer[n]=bdimmer[n];
    }



    //qDebug()<<"escena numero "<<escena;
    //int set=escena;




}

void Serialisimo::guardar(int escena)
{   //GUARDA EN EL ESTADO 1, 2 ó 3 (escena)
    qDebug()<<"guardar escena "<<escena;

    foco1[escena]=foco1[0];
    foco2[escena]=foco2[0];
    colorRGB[escena]=colorRGB[0];  //guarda el color #escena del slot temporal 0
    cortina[escena]=cortina[0];
    dimmer[escena]=dimmer[0];

    qDebug()<<"se guardó el color "<<colorRGB[escena];
    qDebug()<<"se guardó el foco1 en estado "<<foco1[escena];
    qDebug()<<"se guardó el foco2 en estado "<<foco2[escena];
    qDebug()<<"se guardó la cortina en estado "<<cortina[escena];
    qDebug()<<"se guardó el dimmer en estado "<<dimmer[escena];

}

//Para FOCOS
void Serialisimo::setfoco1(int numero)
{
    QString s = QString::number(numero);
    foco1[0]=s; //guarda el estado del foco en una variable temporal foco1[0]
    qDebug()<<"el foco 1 esta en estado"<<foco1[0];

}

int Serialisimo::recuperarfoco1(int numescena)
{
    //
    int s=foco1[numescena].toInt();
    return s;
    //variable temporal
}

void Serialisimo::setfoco2(int numero)
{
    QString s = QString::number(numero);
    foco2[0]=s; //guarda el estado del foco en una variable temporal foco2[0]
    qDebug()<<"el foco 2 esta en estado"<<foco2[0];

}

int Serialisimo::recuperarfoco2(int numescena)
{
    //
    int s=foco2[numescena].toInt();
    return s;
    //variable temporal
}



//para el RGB
QString Serialisimo::getcolorRGB(int numero)
{
    //qDebug()<<"getcolorRGB("<<numero<<")";
    //colorRGB[0]=colorRGB[numero];
    return colorRGB[numero];

}

QString Serialisimo::recuperarcolor()
{
    //qDebug()<<"recuperarcolor() ";
    return coloranterior;
}


QString Serialisimo::obtenercolor(QString color)
{
    //qDebug()<<"obtenercolor("<<color<<")";
    coloranterior=color;

    return coloranterior;

}

//para CORTINA
void Serialisimo::setcortina(int numero)
{
    QString s = QString::number(numero);
    cortina[0]=s; //guarda el estado del foco en una variable temporal foco2[0]
    qDebug()<<" la cortina esta en estado"<<cortina[0];

}

int Serialisimo::recuperarcortina(int numescena)
{
    //
    int s=cortina[numescena].toInt();
    return s;
    //variable temporal
}
//para el DIMMER
void Serialisimo::setdimmer(int numero)
{
    QString s = QString::number(numero);
    dimmer[0]=s; //guarda el estado del dimmer en una variable temporal dimmer[0]
    qDebug()<<" el dimmer esta en estado"<<dimmer[0];
}

int Serialisimo::recuperardimmer(int numescena)
{
    int s=dimmer[numescena].toInt();
    return s;
}







//BOTONES
void Serialisimo::apagartodo()
{
    enviarRGB("#000000");
    enviarfoco(1,0);
    enviarfoco(2,0);
    enviardimmer(0);
    enviarcortina(1,0);

}

void Serialisimo::proyeccion()
{
    //bajar cortina, apagar luces, encender proyector
    enviarRGB("#0000ff");
    enviarfoco(1,255);
    enviarfoco(2,0);
    enviardimmer(100);
    enviarcortina(1,255);

}

void Serialisimo::escenaclases()
{

    //subir cortina, prender luces, apagar poyector
    enviarRGB("#ff0000");
    enviarfoco(1,255);
    enviarfoco(2,255);
    enviardimmer(36);
    enviarcortina(1,0);
}


//ENVIAR ESCENAS
void Serialisimo::enviarfoco(int cto,int estado)
{

    //unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xC0, 0xE4, 0x02, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //ONOFF nuevo
    unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x41, 0x4E, 0xE4, 0x49, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //Mod Smart
    #define buf_size 60
    unsigned char bufferTX[buf_size]; //numbytestosend;
    unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

    rf_send[1]=cto;
    rf_send[2]=estado;
    unsigned char i, chs=0;
    for (i=0; i<17; i++)
        bufferTX[i]=rf_maskDim[i];
    for (i=17; i<25; i++)
        bufferTX[i]=rf_send[i-17];
    for (i=3; i<25; i++)
        chs+=bufferTX[i];
    bufferTX[25]=255-chs;

    QByteArray databuf((char*)bufferTX, 26);
    QByteArray a(databuf.toHex());
    QByteArray bytes= QByteArray::fromHex(a);
    serial->write(bytes);
    //qDebug()<<bytes;
    qDebug()<<"Foco "<<a;


}

void Serialisimo::enviarcortina(int cto, int estado)
{
    unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xC0, 0xE4, 0x18, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

    #define buf_size 60
    unsigned char bufferTX[buf_size]; //numbytestosend;
    unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

    rf_send[1]=cto;
    rf_send[2]=estado;
    unsigned char i, chs=0;
    for (i=0; i<17; i++)
        bufferTX[i]=rf_maskDim[i];
    for (i=17; i<25; i++)
        bufferTX[i]=rf_send[i-17];
    for (i=3; i<25; i++)
        chs+=bufferTX[i];
    bufferTX[25]=255-chs;

    QByteArray databuf((char*)bufferTX, 26);
    QByteArray a(databuf.toHex());
    QByteArray bytes= QByteArray::fromHex(a);
    serial->write(bytes);
    //qDebug()<<bytes;
    qDebug()<<"Cortina "<<a;

}

void Serialisimo::enviardimmer(int numero)
{
        if (numero==100){numero=99;}
        //metodo final

        unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xE9, 0x46, 0xBC, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

        #define buf_size 60
        unsigned char bufferTX[buf_size]; //numbytestosend;
        unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

        rf_send[2]=numero;
        unsigned char i, chs=0;
        for (i=0; i<17; i++)
            bufferTX[i]=rf_maskDim[i];
        for (i=17; i<25; i++)
            bufferTX[i]=rf_send[i-17];
        for (i=3; i<25; i++)
            chs+=bufferTX[i];
        bufferTX[25]=255-chs;

        QByteArray databuf((char*)bufferTX, 26);
        QByteArray a(databuf.toHex());
        QByteArray bytes= QByteArray::fromHex(a);
        serial->write(bytes);
        //qDebug()<<bytes;
        qDebug()<<"Dimmer"<<a;


}

void Serialisimo::enviarRGB(QString color)
{
    //qDebug()<<vistaprevia;
    //if(vistaprevia==1)
    {
        colorRGB[0]=color;

        bool ok;
        int red= color.QString::mid(1,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"red"<<red;
        int green= color.QString::mid(3,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"green"<<green;
        int blue= color.QString::mid(5,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"blue"<<blue;



        unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xCA, 0xAE, 0x94, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

        #define buf_size 60
        unsigned char bufferTX[buf_size]; //numbytestosend;
        unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

        //rf_send[2]=numero;
        rf_send[3]=red;
        rf_send[4]=green;
        rf_send[5]=blue;
        unsigned char i, chs=0;
        for (i=0; i<17; i++)
            bufferTX[i]=rf_maskDim[i];
        for (i=17; i<25; i++)
            bufferTX[i]=rf_send[i-17];
        for (i=3; i<25; i++)
            chs+=bufferTX[i];
        bufferTX[25]=255-chs;

        QByteArray databuf((char*)bufferTX, 26);
        QByteArray a(databuf.toHex());
        QByteArray bytes= QByteArray::fromHex(a);
        serial->write(bytes);
        //qDebug()<<bytes;
        qDebug()<<"RGB: "<<a;


    }





}









