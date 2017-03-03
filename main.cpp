#include <iostream>
#include "comandos.h"
#include "errores.h"

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
          Error error =  ValidarParametros(listaParametros,comando);
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
                    DarParametro(lp,1,p1);
                    DarParametro(lp,2,p2);
                    DarParametro(lp,3,p3);
                    if(ExisteExpresion(listaExpresiones,strToInt(p1))== TRUE &&
                       ExisteExpresion(listaExpresiones,strToInt(p3))== TRUE){
                       ComandoNoAtomica(listaExpresiones,p1,p2,p3);
                    }else{
                        MostrarMensajeError(CANT_PARAM);
                    }
                    strdestruir(p1);
                    strdestruir(p2);
                    strdestruir(p3);
                  }else if(CantidadParametros(listaParametros) == 2){
                    strcrear(p1);
                    strcrear(p2);
                    DarParametro(lp,1,p1);
                    DarParametro(lp,2,p2);
                    if(ExisteExpresion(listaExpresiones,strToInt(p2))== TRUE){
                        ComandoNoAtomica(listaExpresiones,p1,p2,p3);
                    }else{
                        MostrarMensajeError(EXIT_FAILURE);
                    }
                    strdestruir(p1);
                    strdestruir(p2);
                  }

              }else if(streq(comando,"respaldar\0")){
                    string nombreArchivo;
                    string indice;
                    strcrear(nombreArchivo);
                    strcrear(indice);
                    DarParametro(listaParametros,1,indice);
                    DarParametro(listaParametros,2,nombreArchivo);
                    ComandoRespaldar(listaExpresiones, strToInt(indice), nombreArchivo);
                    strdestruir(nombreArchivo);
                    strdestruir(indice);
              }else if(streq(comando,"recuperar\0")){
                  string nombreArch;
                  strcrear(nombreArch);
                  DarParametro(listaParametros,1,nombreArch);
                  ComandoRecuperar(listaExpresiones,nombreArch);
                  strdestruir(nombreArch);
              }else if(streq(comando,"letras\0")){
                    string indice;
                    DarParametro(listaParametros,1,indice);
                    ComandoLetras(listaExpresiones, strToInt(indice));
                    strdestruir(indice);
              }else if(streq(comando,"evaluar\0")){

              }else if(streq(comando,"salir\0")){
                    ComandoSalir(listaExpresiones,listaParametros);
                    salir = TRUE;
              }else if(streq(comando,"mostrar\0")){
                    string indice;
                    DarParametro(listaParametros,1,indice);
                    ComandoMostrar(listaExpresiones,strToInt(indice));
                    strdestruir(indice);
              }
          }else{
                MostrarMensajeError(error);
            }
    }else{
      MostrarMensajeError(COMANDO_INV);
    }
    strdestruir(entrada);
    strdestruir(comando);
    strdestruir(parametros);
  }while(salir != TRUE);


}
