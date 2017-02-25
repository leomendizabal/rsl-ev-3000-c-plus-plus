#ifndef LISTA_EXPRESIONES_H_INCLUDED
#define LISTA_EXPRESIONES_H_INCLUDED
#include"expresion.h"

//Lista de expresion
typedef struct nodoE
{
    Expresion ex;
    nodoE *sig;

} NodoListaE;

typedef NodoListaE * ListaExpresiones;

void CrearLista(ListaExpresiones &l);

Boolean EsVacia(ListaExpresiones l);

Expresion DarExpresion(ListaExpresiones l,int indice);

Expresion PrimerExpresion (ListaExpresiones l);

void Restoceder (ListaExpresiones &l);

void InsFront (ListaExpresiones &l, Expresion e);

void InsUltimo (ListaExpresiones &l, Expresion s);

int UltimoIndice(ListaExpresiones l);

#endif // LISTA_EXPRESIONES_H_INCLUDED
