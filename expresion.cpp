#include"expresion.h"


void CrearExpresion( Expresion &e, ArbolComponentes a, int indice){
      e.arb = a;
      e.indice = indice;
}

Boolean EsAtomica(Expresion e){
    Boolean atomica = FALSE;
    if(CantidadDeNodos(e.arb) == 1)
      atomica = TRUE;
    return atomica;
}

ArbolComponentes DarArbol(Expresion e){
  return e.arb;
}

int DarIndice(Expresion e){
  return e.indice;
}



void BajarExpresion(Expresion e, string nombreArch){
   FILE * f=fopen(nombreArch,"wb");
   BajarInt(e.indice,f);
   BajarArbolAux(e.arb,f);
   fclose(f);
}

void LevantarExpresion(Expresion &e, string nombreArch){
    FILE * f = fopen (nombreArch, "rb");
    LevantarInt(e.indice,f);
    LevantarArbol(e.arb,f);
    fclose(f);
}

void MostrarExpresion(Expresion e){
    printf("%d: ", e.indice);
    MostrarArbol(e.arb);
    printf("\n");
}


void ModificarIndExpresion(Expresion &e,int indice)
{
  e.indice = indice;
}

TipoExpresion EvaluarExpresion(Expresion e){
    ListaLetras letras;
    TipoExpresion tipo;
    int cantidadLetras = 0;
    int iteraciones = 0;
    int combinaciones = 0;

    CrearLista(letras);
    ObtenerLetras(DarArbol(e), letras);
    cantidadLetras = CantidadLetras(letras);

    Boolean resultadoEvaluar = FALSE;
    Boolean resultadoAnterior = FALSE;

    string binario = new char[MAX];
    //strcrear(binario);

    decimalToBinary(iteraciones, cantidadLetras, binario);
    AsignarValor(letras, binario);
    resultadoEvaluar = EvaluarArbol(DarArbol(e), letras);
    resultadoAnterior = resultadoEvaluar;
    combinaciones = DarPotencia(2, cantidadLetras);

    while(resultadoEvaluar == resultadoAnterior && iteraciones< combinaciones){
        strcrear(binario);
        iteraciones++;
        decimalToBinary(iteraciones, cantidadLetras, binario);
        AsignarValor(letras, binario);
        resultadoEvaluar = EvaluarArbol(DarArbol(e), letras);
    }

    if(combinaciones == iteraciones){
        tipo = resultadoEvaluar==TRUE ? TAUTOLOGIA : CONTRADICCION;
    }else{
        tipo = CONTINGENCIA;
    }

    strdestruir(binario);
    //printf("la lista de letras es: \n");
    //MostrarListaLetras(letras);

    return tipo;
}
