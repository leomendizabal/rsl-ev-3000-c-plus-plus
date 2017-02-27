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
   BajarInt(e.indice);
   BajarArbolAux(e.arb,f);
      
}

void LevantarExpresion(Expresion &e, string nombreArch){
    FILE * f = fopen (nombreArch, "rb");
    LevantarInt(e.indice);
    Levantar_Arbol(e.arb,f);
}

void MostrarExpresion(Expresion e){
    printf("%d: ", e.indice);
    MostrarArbol(e.arb);
}
