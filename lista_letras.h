#ifndef LISTA_LETRAS_H_INCLUDED
#define LISTA_LETRAS_H_INCLUDED
#include"letra.h"

//Lista de expresion
typedef struct nodoL
{
    InfoLetra info;
    nodoL *sig;
} NodoLista;

typedef NodoLista * ListaLetras;


#endif // LISTA_LETRAS_H_INCLUDED
