#include "comandos.h"


Boolean ValidarComando(string comando){
    if(streq(comando,"ayuda")){
       return TRUE;
    }else if(streq(comando,"atomica")){
        return TRUE;
    }else if(streq(comando,"noatomica")){
       return TRUE;
    }else if(streq(comando,"respaldar")){
        return TRUE;
    }else if(streq(comando,"recuperar")){
       return TRUE;
    }else if(streq(comando,"letras")){
       return TRUE;
    }else if(streq(comando,"evaluar")){
       return TRUE;
    }else if(streq(comando,"salir")){
        return TRUE;
    }else if(streq(comando,"mostrar")){
       return TRUE;
    }else{
       return FALSE;
    }
}

void ParsearComando(string entrada, string &comando,string &parametros){}
