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
              }else if(streq(comando,"atomica\0")){
                    string p;
                    DarParametro(listaParametros,1,p);
                    ComandoAtomica(listaExpresiones, p);
              }else if(streq(comando,"noatomica\0")){
                  ComandoNoAtomica(listaExpresiones,listaParametros);
              }else if(streq(comando,"respaldar\0")){

              }else if(streq(comando,"recuperar\0")){
                  string nombreArch;
                  strcrear(nombreArch);
                  DarParametro(listaParametros,1,nombreArch);
                  ComandoRecuperar(listaExpresiones,nombreArch);
              }else if(streq(comando,"letras\0")){
                    string indice;
                    DarParametro(listaParametros,1,indice);
                    ComandoLetras(listaExpresiones, strToInt(indice));
              }else if(streq(comando,"evaluar\0")){

              }else if(streq(comando,"salir\0")){
                    ComandoSalir(listaExpresiones,listaParametros);
                    salir = TRUE;
              }else if(streq(comando,"mostrar\0")){
                    string indice;
                    DarParametro(listaParametros,1,indice);
                    ComandoMostrar(listaExpresiones,strToInt(indice));
              }
          }else{
                MostrarMensajeError(error);
            }
    }else{
      MostrarMensajeError(COMANDO_INV);
    }

  }while(salir != TRUE);



}
