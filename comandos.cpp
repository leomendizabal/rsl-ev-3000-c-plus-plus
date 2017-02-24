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


void ParsearComando(string entrada, string &comando,string &parametros){
    string parametrosAux;
    string entradaAux;
    strcrear(parametrosAux);
    strcrear(entradaAux);

    strtrim(entrada, entradaAux);
    strfirst(entradaAux, 0, ' ', comando);          //guarda el comando
    strsplit(entradaAux, ' ', parametrosAux);       //guarda la cadena de parametros
    strtrim(parametrosAux, parametros);             //quita los espacios del principio
}

void ParsearParametros(string parametros,ListaParametros &listaResultado){
    int i = 0;
    string param;
    string restoParam;
    //ListaParametros listaResultado;
    strcrear(param);
    strcrear(restoParam);
    //CrearLista(listaResultado);

    while(strlar(parametros)>0){
        strfirst(parametros, 0, ' ', param);            //obtiene el primer string hasta el espacio
        InsUltimo(listaResultado, param);               //inserta un nodo con el parametro a la lista
        strsplit(parametros, ' ', parametros);          //guarda en restoParam toda la cadena menos el primer string
        strtrim(parametros, parametros);
    }

    //printf("Lista: ");
    //Mostrar(listaResultado);
    //return listaResultado;

}

void ComandoAyuda(string  comando){
      printf("\n========= ");print(comando);printf(" =========\n");
      if(streq(comando,"ayuda\0")){
        printf("Despliega una ayuda sobre la sintaxis del comando especificado. \n");
      }else if(streq(comando,"atomica\0")){
        printf("Crea una nueva expresión booleana atómica (es decir, una letra proposicional)\n");
        printf(" y le asigna el próximo índice disponible. \n");
      }else if(streq(comando,"noatomica\0")){
        printf("Crea una nueva expresión booleana no atómica en base a otra(s) ya \n");
        printf("existente(s) y le asigna el próximo índice disponible. La expresión \n");
        printf("existente(s) y le asigna el próximo índice disponible. La expresión \n");
        printf("ingresada a continuación del comando necesariamente debe ser de \n");
        printf("alguna de las siguientes formas: n & m, n | m, ! n (siendo n, m números de índice válidos). \n");
      }else if(streq(comando,"mostrar\0")){
        printf("Se muestra la expresión booleana identificada por el índice n. Debe \n");
        printf("mostrarse totalmente parentizada y con un blanco separando cada \n");
        printf("operador booleano de la(s) subexpresión(es) a la(s) que afecta \n");
      }else if(streq(comando,"respaldar\0")){
        printf("Respalda la expresión identificada por el índice n en el archivo nombrearchivo.dat. \n");
      }else if(streq(comando,"letras\0")){
        printf("Emite un listado de las letras proposicionales que ocurren en la \n");
        printf("expresión identificada por el índice n. Si alguna letra proposicional \n");
        printf("ocurre más de una vez en la expresión, se listará por pantalla una sola vez. \n");
      }else if(streq(comando,"evaluar\0")){
        printf("Determina si la expresión identificada por el índice n es una \n");
        printf("tautología (o sea, siempre es verdadera, sin importar los valores de \n");
        printf("sus subexpresiones), una contradicción (o sea, siempre es falsa, sin \n");
        printf("importar los valores de sus subexpresiones) o una contingencia (o \n");
        printf("sea, no es tautología ni contradicción). \n");
      }else if(streq(comando,"salir\0")){
        printf("Finaliza la ejecución de la aplicación. Al hacerlo, debe liberar toda la \n");
        printf("memoria dinámica usada durante la ejecución. \n");
      }else if(streq(comando,"recuperar\0")){
        printf("Recupera a memoria la expresión guardada en el archivo nombrearchivo.dat y le asigna el próximo índice disponible.");
      }



}







