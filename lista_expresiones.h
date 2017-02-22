#ifndef LISTA_EXPRESIONES_H_INCLUDED
#define LISTA_EXPRESIONES_H_INCLUDED
#include"expresion.h"

//Lista de expresion
typedef struct nodoL
{
    Expresion ex;
    nodoL *sig;
} NodoLista;

typedef NodoLista * ListaExpresiones;


#endif // LISTA_EXPRESIONES_H_INCLUDED
