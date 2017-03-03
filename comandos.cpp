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
    //MostrarParametros(listaResultado);
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

void ComandoAtomica(ListaExpresiones &l, string p){
    Componente c;
    ArbolComponentes arbol;
    Expresion e;
    char letraProposicional = p[0];

    CrearVacio(arbol);

    int indice = UltimoIndice(l) + 1;
    CargarDato(c, 0, letraProposicional, LETRA);          //cargo el componente con la letra proposicional

    Insertar(arbol, c);                     //inserto el componente en ArbolComponente
    CrearExpresion(e, arbol, indice);       //creo una expresion con el indice y el arbol
    InsUltimo(l, e);                        //inserto la expresion en la lista de expresiones
    MostrarExpresion(e);
   // MostrarListaExpresiones(l);
}

void ComandoMostrar(ListaExpresiones l,int ind)
{
  if (ExisteExpresion(l,ind)==TRUE)
  {
     Expresion exp;
     DarExpresion(l,ind, exp);
     MostrarArbol(DarArbol(exp));
     printf("\n");
  }
  else
    MostrarMensajeError(NO_EXISTE_EXP);
}

void ComandoLetras(ListaExpresiones l, int indice){

    if(ExisteExpresion(l, indice)==TRUE){
        ListaLetras letras;
        CrearLista(letras);

        Expresion e;
        DarExpresion(l, indice, e);

        ObtenerLetras(DarArbol(e), letras);

        printf("Lista de la expresion %d: ", indice);
        MostrarListaLetras(letras);
        printf("\n");
    }else{
        MostrarMensajeError(NO_EXISTE_EXP);
    }
}



void ComandoSalir(ListaExpresiones &le,ListaParametros &lp){
   EliminarLista(le);
   EliminarLista(lp);
   printf("hasta la proxima\n");
}





void ComandoNoAtomica(ListaExpresiones &le,int cant,string p1,string p2,string p3){
    Expresion e1,e2;
    ArbolComponentes arb;
    CrearVacio(arb);
    if(cant == 3){
       DarExpresion(le,strToInt(p1),e1);
       DarExpresion(le,strToInt(p3),e2);
       Componente comp;
       CargarDato(comp,0,charAt(p2,0),OPERADOR);
       CrearArbol(arb,DarArbol(e1),DarArbol(e2),comp);
    }else if(cant == 2){
        DarExpresion(le,strToInt(p2),e1);
        Componente comp;
        CargarDato(comp,0,charAt(p1,0),OPERADOR);
        CrearArbol(arb,NULL,DarArbol(e1),comp);
    }
    Expresion expr;
    int indice = UltimoIndice(le) + 1;
    CrearExpresion(expr,arb,indice);
    InsUltimo(le,expr);
    MostrarExpresion(expr);
    //MostrarListaExpresiones(le);

}



void ComandoRespaldar(ListaExpresiones le,int indice,string nombreArch){
    Expresion e;
    if(ExisteExpresion(le, indice)==TRUE){
        DarExpresion(le, indice, e);
        BajarExpresion(e, nombreArch);
        printf("expresion respaldada correctamente\n");
    }
    else
        MostrarMensajeError(NO_EXISTE_EXP);

}

void ComandoRecuperar(ListaExpresiones &le,string nombreArch){


if (EsNombreValido(nombreArch)==TRUE){        //Verifica si el nombre del parametro es sintacticamente correcto
    if (Existe(nombreArch) == TRUE)              //Verifica si el archivo existe en disco
       {
           ArbolComponentes arb;
           CrearVacio(arb);
           Expresion exp;
           int indi = UltimoIndice(le) + 1;   // retorna en int el ultimo indice disponible en la lista de expresiones
           CrearExpresion(exp,arb,indi);
           LevantarExpresion(exp,nombreArch);      //Levanta a memoria la expresion guardada en el archivo
           ModificarIndExpresion(exp,indi);      // Asigna a la expresion el ultimo indice disponibe en la lista
           InsUltimo(le,exp);              //Inserta la nueva expresion al final de la lista de expresiones
           MostrarExpresion(exp);         //Muestra en pantalla la expresion
       }
    else
        MostrarMensajeError(ARCH_NO_EXISTE);
    }
else
    MostrarMensajeError(NOM_ARCH_INV);
}

void ComandoEvaluar(ListaExpresiones le,int indice)
{}



