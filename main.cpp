#include <iostream>
#include "comandos.h"
#include "errores.h"
#include "confirmacion.h"

int main(){

  string entrada, comando, parametros;
  Boolean salir = FALSE;
  ListaExpresiones listaExpresiones;
  ListaParametros listaParametros;

  CrearLista(listaExpresiones);

 do{
    //Inicializo la entrada, el comando ingresado y los parametros cada vez que se ingresa
    strcrear(entrada);
    strcrear(comando);
    strcrear(parametros);

    CrearLista(listaParametros);

     //Leo la entrada
    scan(entrada);
    strToLowerCase(entrada); //pasa a minuscula la entrada completa

    //Parseo
    ParsearComando(entrada,comando,parametros);
   // print(comando);
    ParsearParametros(parametros,listaParametros);
   // MostrarParametros(listaParametros);
    if(ValidarComando(comando) == TRUE) {
          Error error = NO_ERR;
          string etiqueta;
          strcrear(etiqueta);
          ValidarParametros(listaParametros,comando,error,etiqueta);
          if(error == NO_ERR){
              if(streq(comando,"ayuda\0")){
                    string p;
                    strcrear(p);
                    DarParametro(listaParametros,1,p);
                    ComandoAyuda(p);
                    strdestruir(p);
              }else if(streq(comando,"atomica\0")){
                   string p;
                    DarParametro(listaParametros,1,p);
                    ComandoAtomica(listaExpresiones, p);
                    strdestruir(p);
              }else if(streq(comando,"noatomica\0")){
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
                    MostrarMensajeError(CANT_PARAM,comando,CantidadParametrosComando(comando));
                  }

              }else if(streq(comando,"respaldar\0")){
                    string nombreArchivo;
                    string indice;
                    strcrear(nombreArchivo);
                    strcrear(indice);
                    DarParametro(listaParametros,1,indice);
                    DarParametro(listaParametros,2,nombreArchivo);
                    if(ExisteExpresion(listaExpresiones, strToInt(indice))==TRUE){
                        ComandoRespaldar(listaExpresiones, strToInt(indice), nombreArchivo);
                        MostrarMensajeConfirmacion(RESP,indice,nombreArchivo);
                    }else{
                        MostrarMensajeError(NOM_ARCH_INV,indice,0);
                    }
                    strdestruir(nombreArchivo);
                    strdestruir(indice);
              }else if(streq(comando,"recuperar\0")){
                  string nombreArch;
                  strcrear(nombreArch);
                  DarParametro(listaParametros,1,nombreArch);
                  if (Existe(nombreArch) == TRUE) {
                     ComandoRecuperar(listaExpresiones,nombreArch);
                  }else{
                    MostrarMensajeError(ARCH_NO_EXISTE,nombreArch,0);
                  }
                  strdestruir(nombreArch);
              }else if(streq(comando,"letras\0")){
                    string indice;
                    DarParametro(listaParametros,1,indice);
                    if(ExisteExpresion(listaExpresiones, strToInt(indice))==TRUE){
                        ComandoLetras(listaExpresiones, strToInt(indice));
                    }else{
                        MostrarMensajeError(NO_EXISTE_EXP,indice,0);
                    }
                    strdestruir(indice);
              }else if(streq(comando,"evaluar\0")){

              }else if(streq(comando,"salir\0")){
                    ComandoSalir(listaExpresiones,listaParametros);
                    MostrarMensajeConfirmacion(SALUDO,"","");
                    salir = TRUE;
              }else if(streq(comando,"mostrar\0")){
                    string indice;
                    strcrear(indice);
                    DarParametro(listaParametros,1,indice);
                    if (ExisteExpresion(listaExpresiones,strToInt(indice))==TRUE){
                       ComandoMostrar(listaExpresiones,strToInt(indice));
                    }else{
                        MostrarMensajeError(NO_EXISTE_EXP,indice,0);
                    }
                    strdestruir(indice);
              }
          }else{
                MostrarMensajeError(error,etiqueta,CantidadParametrosComando(comando));
          }
          strdestruir(etiqueta);
    }else{
      MostrarMensajeError(COMANDO_INV,comando,0);
    }
    strdestruir(entrada);
    strdestruir(comando);
    strdestruir(parametros);
  }while(salir != TRUE);

}
