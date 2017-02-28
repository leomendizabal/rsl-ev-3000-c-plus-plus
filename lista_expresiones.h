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

Boolean ExisteExpresion(ListaExpresiones l,int indice);

//PRECONDICION: la expresion existe en la lista
void DarExpresion(ListaExpresiones l,int indice, Expresion &e);

Expresion PrimerExpresion (ListaExpresiones l);

void Restoceder (ListaExpresiones &l);

void InsFront (ListaExpresiones &l, Expresion e);

void InsUltimo (ListaExpresiones &l, Expresion s);

int UltimoIndice(ListaExpresiones l);

void MostrarListaExpresiones(ListaExpresiones l);

void EliminarLista(ListaExpresiones &l);

#endif // LISTA_EXPRESIONES_H_INCLUDED
