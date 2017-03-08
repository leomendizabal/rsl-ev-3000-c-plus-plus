#include "comandos.h"


Comando ValidarComando(string comando){
		 char ayudaArr[MAX] = "ayuda\0";
		 string ayuda = ayudaArr;
		 char atomicaArr[MAX] = "atomica\0";
		 string atomica = atomicaArr;
		 char noatomicaArr[MAX] = "noatomica\0";
		 string noatomica = noatomicaArr;
		 char mostrarArr[MAX] = "mostrar\0";
		 string mostrar = mostrarArr;
		 char respaldarArr[MAX] = "respaldar\0";
		 string respaldar = respaldarArr;
		 char recuperarArr[MAX] = "recuperar\0";
		 string recuperar = recuperarArr;
		 char letrasArr[MAX] = "letras\0";
		 string letras =letrasArr;
		 char evaluarArr[MAX] = "evaluar\0";
		 string evaluar = evaluarArr;
		 char salirArr[MAX] =  "salir\0";
		 string salir = salirArr;

		if(streq(comando,ayuda)){
       		return AYU;
	    }else if(streq(comando,atomica)){
	        return ATO;
	    }else if(streq(comando,noatomica)){
	       return NOATO;
	    }else if(streq(comando,respaldar)){
	        return RES;
	    }else if(streq(comando,recuperar)){
	       return REC;
	    }else if(streq(comando,letras)){
	       return LET;
	    }else if(streq(comando,evaluar)){
	       return EVA;
	    }else if(streq(comando,salir)){
	        return SAL;
	    }else if(streq(comando,mostrar)){
	       return MOS;
	    }else{
	       return INV;
	    }
	    strdestruir(mostrar);
	    strdestruir(salir);
	    strdestruir(evaluar);
	    strdestruir(letras);
	    strdestruir(recuperar);
	    strdestruir(noatomica);
	    strdestruir(respaldar);
	    strdestruir(atomica);
	    strdestruir(ayuda);

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
    string param;
    string restoParam;

    strcrear(param);
    strcrear(restoParam);

    while(strlar(parametros)>0){
        //strcrear(param);
        strfirst(parametros, 0, ' ', param);            //obtiene el primer string hasta el espacio
        InsUltimo(listaResultado, param);              //inserta un nodo con el parametro a la lista
        strsplit(parametros, ' ', parametros);          //guarda en restoParam toda la cadena menos el primer string
        strcop(restoParam,parametros);
        strtrim(restoParam, parametros);
    }
    strdestruir(param);
    strdestruir(restoParam);

}
void ComandoAyuda(Comando comando){

      switch(comando){
            case AYU:
                printf("Despliega una ayuda sobre la sintaxis del comando especificado. \n");
                break;
            case ATO:
                printf("Crea una nueva expresión booleana atómica (es decir, una letra proposicional)\n");
                printf(" y le asigna el próximo índice disponible. \n");
                break;
            case NOATO:
                printf("Crea una nueva expresión booleana no atómica en base a otra(s) ya \n");
                printf("existente(s) y le asigna el próximo índice disponible. La expresión \n");
                printf("existente(s) y le asigna el próximo índice disponible. La expresión \n");
                printf("ingresada a continuación del comando necesariamente debe ser de \n");
                printf("alguna de las siguientes formas: n & m, n | m, ! n (siendo n, m números de índice válidos). \n");
                break;
            case MOS:
                printf("Se muestra la expresión booleana identificada por el índice n. Debe \n");
                printf("mostrarse totalmente parentizada y con un blanco separando cada \n");
                printf("operador booleano de la(s) subexpresión(es) a la(s) que afecta \n");
                break;
            case RES:
                printf("Respalda la expresión identificada por el índice n en el archivo nombrearchivo.dat. \n");
                break;
            case REC:
                printf("Recupera a memoria la expresión guardada en el archivo nombrearchivo.dat y le asigna el próximo índice disponible.");
                break;
            case LET:
                printf("Emite un listado de las letras proposicionales que ocurren en la \n");
                printf("expresión identificada por el índice n. Si alguna letra proposicional \n");
                printf("ocurre más de una vez en la expresión, se listará por pantalla una sola vez. \n");
                break;
            case EVA:
                printf("Determina si la expresión identificada por el índice n es una \n");
                printf("tautología (o sea, siempre es verdadera, sin importar los valores de \n");
                printf("sus subexpresiones), una contradicción (o sea, siempre es falsa, sin \n");
                printf("importar los valores de sus subexpresiones) o una contingencia (o \n");
                printf("sea, no es tautología ni contradicción). \n");
                break;
            case SAL:
                printf("Finaliza la ejecución de la aplicación. Al hacerlo, debe liberar toda la \n");
                printf("memoria dinámica usada durante la ejecución. \n");
                break;
            default:break;
      }
}

void ComandoAtomica(ListaExpresiones &l, string p){
    Componente c;
    ArbolComponentes arbol;
    Expresion e;
    char letraProposicional = charAt(p,0);

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
     Expresion exp;
     DarExpresion(l,ind, exp);
     MostrarArbol(DarArbol(exp));
     printf("\n");

}

void ComandoLetras(ListaExpresiones l, int indice){
    ListaLetras letras;
    CrearLista(letras);

    Expresion e;
    DarExpresion(l, indice, e);

    ObtenerLetras(DarArbol(e), letras);
    MostrarListaLetras(letras);
}



void ComandoSalir(ListaExpresiones &le,ListaParametros &lp){
   EliminarLista(le);
   EliminarLista(lp);
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
    DarExpresion(le, indice, e);
    BajarExpresion(e, nombreArch);
}

void ComandoRecuperar(ListaExpresiones &le,string nombreArch){

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

void ComandoEvaluar(ListaExpresiones le,int indice){
    Expresion e;
    TipoExpresion tipoExpresion;

    DarExpresion(le, indice, e);
    tipoExpresion = EvaluarExpresion(e);

    switch(tipoExpresion){
        case TAUTOLOGIA:
            MostrarMensajeConfirmacion(TAUTO,DarIndice(e),"");
            break;
        case CONTRADICCION:
             MostrarMensajeConfirmacion(CONTRA,DarIndice(e),"");
            break;
        case CONTINGENCIA:
            MostrarMensajeConfirmacion(CONTI,DarIndice(e),"");
            break;
        default:
            break;
    }

    //printf("\n");
}


int CantidadParametrosComando(Comando comando){
    switch(comando){
        case AYU:
        case ATO:
        case MOS:
        case EVA:
        case LET:
        case REC: return 1;break;
        case RES: return 2;break;
        case SAL: return 0;break;
        case NOATO: return 5; break;
        default:break;
    }
    return -1;
}


