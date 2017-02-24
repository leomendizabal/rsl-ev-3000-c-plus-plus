#include <iostream>
#include "comandos.h"
#include "errores.h"
#include "lista_parametros.h"

int main(){

  string entrada, comando, parametros;
  Boolean salir = FALSE;
  ListaParametros listaParametros;
  //Inicializo
  strcrear(entrada);
  strcrear(comando);
  strcrear(parametros);
  CrearLista(listaParametros);


 do{
     //Leo la entrada
    scan(entrada);
    //Parseo
    ParsearComando(entrada,comando,parametros);
   // print(comando);
    ParsearParametros(parametros,listaParametros);
   // MostrarParametros(listaParametros);
    if(ValidarComando(comando) == TRUE) {
      if(streq(comando,"ayuda\0")){
         Error errorA =  ValidarParametros(listaParametros,comando);
         if( errorA == NO_ERR){
            string p;
            strcrear(p);
            DarParametro(listaParametros,1,p);
            ComandoAyuda(p);
         }else{
            MostrarMensajeError(errorA);
         }

      }else if(streq(comando,"atomica\0")){

      }else if(streq(comando,"noatomica\0")){

      }else if(streq(comando,"respaldar\0")){

      }else if(streq(comando,"recuperar\0")){

      }else if(streq(comando,"letras\0")){

      }else if(streq(comando,"evaluar\0")){

      }else if(streq(comando,"salir\0")){
        salir = TRUE;
      }else if(streq(comando,"mostrar\0")){

      }
    }else{
      MostrarMensajeError(COMANDO_INV);
    }
  }while(salir != TRUE);



}
