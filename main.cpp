#include <iostream>
#include "comandos.h"
#include "errores.h"
#include "lista_parametros.h"

int main(){

  string entrada, comando, parametros;
  Boolean salir = FALSE;
  //Inicializo
  strcrear(entrada);
  strcrear(comando);
  strcrear(parametros);
  //Leo la entrad
  scan(entrada);
  ParsearComando(entrada,comando,parametros);

 do{
    if(ValidarComando(comando) == TRUE) {
      if(streq(comando,"ayuda")){

      }else if(streq(comando,"atomica")){

      }else if(streq(comando,"noatomica")){

      }else if(streq(comando,"respaldar")){

      }else if(streq(comando,"recuperar")){

      }else if(streq(comando,"letras")){

      }else if(streq(comando,"evaluar")){

      }else if(streq(comando,"salir")){
        salir = TRUE;
      }else if(streq(comando,"mostrar")){

      }
    }else{
      MostrarMensajeError(COMANDO_INV);
    }
  }while(salir != TRUE);



}
