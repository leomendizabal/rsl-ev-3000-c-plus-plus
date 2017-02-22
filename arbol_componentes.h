#ifndef ARBOL_COMPONENTES_H_INCLUDED
#define ARBOL_COMPONENTES_H_INCLUDED
#include "Componente.h"

typedef struct nodoA
{
    Componente info;
    nodoA *Hizq;
    nodoA *Hder;
} NodoArb;

typedef NodoArb *ArbolComponentes;


#endif // ARBOL_COMPONENTES_H_INCLUDED
