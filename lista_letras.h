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

void CrearLista(ListaLetras &l);

Boolean EsVacia(ListaLetras l);

Boolean DarValorLetra(ListaLetras l,char s);

Boolean ExisteLetra(ListaLetras l,char letra);

void Restoceder (ListaLetras &l);

void InsFront (ListaLetras &l, InfoLetra info);

void InsUltimo (ListaLetras &l, InfoLetra info);

#endif // LISTA_LETRAS_H_INCLUDED
