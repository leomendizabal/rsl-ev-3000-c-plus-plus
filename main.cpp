#include <iostream>
#include "comandos.h"



int main(){
  string entrada, comando, parametros;
  Boolean out = FALSE;
  ListaExpresiones listaExpresiones;
  ListaParametros listaParametros;

  CrearLista(listaExpresiones);
      //Inicializo la entrada, el comando ingresado y los parametros cada vez que se ingresa
    strcrear(entrada);
    strcrear(comando);
    strcrear(parametros);

 do{

    CrearLista(listaParametros);
     //Leo la entrada
    printf("Ingrese comando:    ");
    scan(entrada);
    strToLowerCase(entrada); //pasa a minuscula la entrada completa

    //Parseo
    ParsearComando(entrada,comando,parametros);
   // print(comando);
    ParsearParametros(parametros,listaParametros);
   // MostrarParametros(listaParametros);
    printf("Resultado:          ");
    Comando cmd = ValidarComando(comando);
    if(cmd != INV) {
          Error error = NO_ERR;
          string etiqueta;
          strcrear(etiqueta);
          ValidarParametros(listaParametros,cmd,comando,error,etiqueta);
          if(error == NO_ERR){
              switch(cmd){
                case AYU:
                    string p;
                    strcrear(p);
                    DarParametro(listaParametros,1,p);
                    if(ValidarComando(p) == INV){
                        MostrarMensajeError(COMANDO_INV,p,0);
                    }else{
                        ComandoAyuda(ValidarComando(p));
                    }
                    strdestruir(p);
                    break;
                case ATO:
                    string atom;
                    DarParametro(listaParametros,1,atom);
                    ComandoAtomica(listaExpresiones, atom);
                    strdestruir(atom);
                    break;
                case MOS:
                    string indice;
                    strcrear(indice);
                    DarParametro(listaParametros,1,indice);
                    if (ExisteExpresion(listaExpresiones,strToInt(indice))==TRUE){
                       ComandoMostrar(listaExpresiones,strToInt(indice));
                    }else{
                        MostrarMensajeError(NO_EXISTE_EXP,indice,0);
                    }
                    strdestruir(indice);
                    break;
                case EVA:
                    string indiceEv;
                    strcrear(indiceEv);
                    DarParametro(listaParametros,1,indiceEv);
                    if(ExisteExpresion(listaExpresiones, strToInt(indiceEv))==TRUE){
                        ComandoEvaluar(listaExpresiones, strToInt(indiceEv));
                    }else{
                        MostrarMensajeError(NO_EXISTE_EXP,indiceEv,0);
                    }
                    strdestruir(indiceEv);
                    break;
                case LET:
                    string indiceLet;
                    strcrear(indiceLet);
                    DarParametro(listaParametros,1,indiceLet);
                    if(ExisteExpresion(listaExpresiones, strToInt(indiceLet))==TRUE){
                        ComandoLetras(listaExpresiones, strToInt(indiceLet));
                    }else{
                        MostrarMensajeError(NO_EXISTE_EXP,indiceLet,0);
                    }
                    strdestruir(indiceLet);
                    break;
                case REC:
                    string nombreArch;
                    strcrear(nombreArch);
                    DarParametro(listaParametros,1,nombreArch);
                    if (Existe(nombreArch) == TRUE) {
                        ComandoRecuperar(listaExpresiones,nombreArch);
                    }else{
                        MostrarMensajeError(ARCH_NO_EXISTE,nombreArch,0);
                    }
                    strdestruir(nombreArch);
                    break;
                case RES:
                    string nombreArchivo;
                    string indiceRes;
                    strcrear(nombreArchivo);
                    strcrear(indiceRes);
                    DarParametro(listaParametros,1,indiceRes);
                    DarParametro(listaParametros,2,nombreArchivo);
                    if(ExisteExpresion(listaExpresiones, strToInt(indiceRes))==TRUE){
                        ComandoRespaldar(listaExpresiones, strToInt(indiceRes), nombreArchivo);
                        MostrarMensajeConfirmacion(RESP,strToInt(indiceRes),nombreArchivo);
                    }else{
                        MostrarMensajeError(NOM_ARCH_INV,indiceRes,0);
                    }
                    strdestruir(nombreArchivo);
                    strdestruir(indiceRes);
                    break;
                case SAL:
                    ComandoSalir(listaExpresiones,listaParametros);
                    MostrarMensajeConfirmacion(SALUDO,0,"");
                    out = TRUE;
                    break;
                case NOATO:
                      string p1,p2,p3;
                      if(CantidadParametros(listaParametros) == 3){
                        strcrear(p1);
                        strcrear(p2);
                        strcrear(p3);
                        DarParametro(listaParametros,1,p1);
                        DarParametro(listaParametros,2,p2);
                        DarParametro(listaParametros,3,p3);
                        Boolean ex1 = ExisteExpresion(listaExpresiones,strToInt(p1));
                        Boolean ex2 = ExisteExpresion(listaExpresiones,strToInt(p3));
                        if( ex1 == TRUE && ex2 == TRUE){
                           ComandoNoAtomica(listaExpresiones,CantidadParametros(listaParametros),p1,p2,p3);
                        }else{
                            MostrarMensajeError(NO_EXISTE_EXP,(ex1 == TRUE)? p3: p1,0);
                        }
                        strdestruir(p1);
                        strdestruir(p2);
                        strdestruir(p3);
                      }else if(CantidadParametros(listaParametros) == 2){
                        strcrear(p1);
                        strcrear(p2);
                        DarParametro(listaParametros,1,p1);
                        DarParametro(listaParametros,2,p2);
                        if(ExisteExpresion(listaExpresiones,strToInt(p2))== TRUE){
                            ComandoNoAtomica(listaExpresiones,CantidadParametros(listaParametros),p1,p2,p3);
                        }else{
                            MostrarMensajeError(NO_EXISTE_EXP,p2,0);
                        }
                        strdestruir(p1);
                        strdestruir(p2);
                      }else{
                        MostrarMensajeError(CANT_PARAM,comando,CantidadParametrosComando(cmd));
                      }
                      break;
                      default:break;
                    }
           }else{
              MostrarMensajeError(error,etiqueta,CantidadParametrosComando(cmd));
          }
          strdestruir(etiqueta);
    }else{
      MostrarMensajeError(COMANDO_INV,comando,0);
    }

  }while(out != TRUE);
   strdestruir(entrada);
   strdestruir(comando);
   strdestruir(parametros);

}
