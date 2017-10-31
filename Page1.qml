import QtQuick 2.7
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2
import QtQml 2.2

Page1Form {
    width: 800
    height: 480
    //mouseArea12.on
    /*Connections{
        target: serialito
        onUserNameChanged:
            botontest.visible=false;
        //onvaluechanged:

    }*/

    //clock.onNowChanged:  {   botontest.visible=false;   }

    botonvariable.onClicked: {
        //activateScreen();
}
    botontest.onClicked: {
        //estadopantalla.value

        //console.log("el estadopantalla es "+estadopantalla.value);
        //estadopantalla.m
    }

    grupo1.onPressed:   {
        //console.log("valor de pantalla encendida es "+serialito.vistaprevia);
        activateScreen();

        //if(serialito.numescena===1)

        /*
        if(serialito.pantallaencendida===1)
        {botontest.visible=true;}
        else
        {botontest.visible=false;}
        */

        //visible=false;

    }


    checkvistaprevia.onClicked: {
        if(checkvistaprevia.checked)
        {
            serialito.vistaprevia=1.0;
            console.log("vistaprevia"+serialito.vistaprevia);

        }
        else
        {//console.log("vistaprevia desactivada");
            serialito.vistaprevia=0;
            console.log("vistaprevia"+serialito.vistaprevia);

        }
}
    botonestablecer.onClicked: {//restablecer

        //foco1[4]={"0","1","0","0"};

        /*
        switchDelegate.checked=1;
        switchDelegate1.checked=1;
        colorseleccionado.color = "#ff0000";
        botonarriba.checked=1;
        dial.value=100;



        serialito.setfoco1(1);
        serialito.setfoco1(1);
        serialito.obtenercolor(ff0000)
        serialito.setcortina(1);
        serialito.setdimmer(100);
        serialito.guardar(1);
        */

        serialito.restablecer(); //restablecer


}
    botonguardar.onClicked: {
        serialito.guardar(serialito.numescena);

}

//BOTONES para SELECCIONAR ESCENA
    botonclases.onClicked:     {serialito.numescena=1;//if vistaprevia=1...
        switchDelegate.checked=serialito.recuperarfoco1(1);
        switchDelegate1.checked=serialito.recuperarfoco2(1);
        colorseleccionado.color = serialito.getcolorRGB(1);
        if(serialito.recuperarcortina(1)){botonarriba.checked=1;} else{botonabajo.checked=1;} //cortina
        dial.value=(serialito.recuperardimmer(1)/100);


    }

    botonproyeccion.onClicked: {serialito.numescena=2;
        switchDelegate.checked=serialito.recuperarfoco1(2);
        switchDelegate1.checked=serialito.recuperarfoco2(2);
        colorseleccionado.color = serialito.getcolorRGB(2);

        if(serialito.recuperarcortina(2)){botonarriba.checked=1;} else{botonabajo.checked=1;} //cortina
        dial.value=(serialito.recuperardimmer(2)/100);
    }

    botonapagartodo.onClicked: {serialito.numescena=3;
        switchDelegate.checked=serialito.recuperarfoco1(3);
        switchDelegate1.checked=serialito.recuperarfoco2(3);
        colorseleccionado.color = serialito.getcolorRGB(3);

        if(serialito.recuperarcortina(3)){botonarriba.checked=1;} else{botonabajo.checked=1;} //cortina

        dial.value=(serialito.recuperardimmer(3)/100);
        //console.log("el foco 1 estaba en "+serialito.recuperarfoco1(3));
        //console.log(serialito.getcolorRGB(3));
        /*
        switchDelegate.checked=0;
        switchDelegate1.checked=0;
        botonabajo.checked=1;//botonabajo.toggle(); //ok
        */


    }







//del RGB
    areaselectRGB.onClicked: {

        colorDialog.open();
}

    switchapagar.onClicked: {

        if(switchapagar.checked)
        {
            colorseleccionado.color = serialito.recuperarcolor();
        }
        else
        {//console.log("no checked");
            colorseleccionado.color = "#000000"
            serialito.enviarRGB("#000000");
        }
}

    colorseleccionado.onColorChanged: {

        if(colorseleccionado.color=="#000000")
        {switchapagar.checked= false;}
        else
        {switchapagar.checked= true;
            serialito.obtenercolor(colorseleccionado.color);

        }

        serialito.enviarRGB(colorseleccionado.color);
    }


//DE LOS FOCOS
    switchDelegate.onCheckedChanged:  {

        if(switchDelegate.checked)    {   serialito.setfoco1(1);   }
        else   {   serialito.setfoco1(0);     }
        //console.log("el serialito.foco1 esta en "+ serialito.setfoco1());

        if(switchDelegate.checked)     {serialito.enviarfoco(1,255);}
        else       {serialito.enviarfoco(1,0);}
}

    switchDelegate1.onCheckedChanged://onPositionChanged:
    {
        if(switchDelegate1.checked)    {   serialito.setfoco2(1);     }
        else     {   serialito.setfoco2(0);    }

        if(switchDelegate1.checked)       {  serialito.enviarfoco(2,255);   }
        else {serialito.enviarfoco(2,0);  }
    }




//Cortina
    botonarriba.onCheckedChanged: { //oncheckedchanged
        if(botonarriba.checked){  serialito.setcortina(1);}
        else{serialito.setcortina(0);    }

        if(botonarriba.checked){ serialito.enviarcortina(1,255); }
        else{   serialito.enviarcortina(1,0);   }
    }

        botonabajo.onClicked: {
            //serialito.setcortina(0);
            //serialito.enviarcortina(1,0);
        }



//DIAL - Dimmer

    dial.onPositionChanged: {
        porcentaje.text=((dial.position*100).toFixed(0));
        //console.log("dial.position indica "+dial.position*100);
    }


    dial.onValueChanged: {
        serialito.setdimmer(100*dial.value);
        serialito.enviardimmer(100*dial.value);
        //console.log("dial.value indica"+100*dial.value);

    }
    dial.onPressedChanged:{
        if((dial.position!=dial.value)&&(dial.pressed==0))
        {   //console.log("value y position son diferentes");
            dial.value=dial.position;
        }
    }


}

