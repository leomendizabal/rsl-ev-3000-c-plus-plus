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

    CrearLista(letras);
    ObtenerLetras(DarArbol(e), letras);
    cantidadLetras = CantidadLetras(letras);

    Boolean resultadoEvaluar = FALSE;
    Boolean resultadoAnterior = FALSE;

    string binario;
    strcrear(binario);

    decimalToBinary(iteraciones, cantidadLetras, binario);
    AsignarValor(letras, binario);
    resultadoEvaluar = EvaluarArbol(DarArbol(e), letras);
    resultadoAnterior = resultadoEvaluar;

    while(resultadoEvaluar == resultadoAnterior && iteraciones<DarPotencia(2, cantidadLetras)){
        iteraciones++;
        decimalToBinary(iteraciones, cantidadLetras, binario);
        AsignarValor(letras, binario);
        resultadoEvaluar = EvaluarArbol(DarArbol(e), letras);
    }

    if(DarPotencia(2, cantidadLetras)==(iteraciones)){
        tipo = resultadoEvaluar==TRUE ? TAUTOLOGIA : CONTRADICCION;
    }else{
        tipo = CONTINGENCIA;
    }

    strdestruir(binario);
    //printf("la lista de letras es: \n");
    //MostrarListaLetras(letras);

    return tipo;
}
