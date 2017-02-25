#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include "arbol_componentes.h"

#include "arbol_componentes.h"

//Expresion corresponde a un struct con un arbol y el numero de expresion
typedef struct
{
    ArbolComponentes arb;
    int indice;
} Expresion;


void CrearExpresion( Expresion &e, ArbolComponentes a, int indice);

Boolean EsAtomica(Expresion e);

ArbolComponentes DarArbol(Expresion e);

int DarIndice(Expresion e);

void BajarExpresion(Expresion e, string nombreArch);

void LevantarExpresion(Expresion &e, string nombreArch);

#endif // EXPRESION_H_INCLUDED
