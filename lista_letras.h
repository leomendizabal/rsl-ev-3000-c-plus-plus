#ifndef LISTA_LETRAS_H_INCLUDED
#define LISTA_LETRAS_H_INCLUDED
#include "letra.h"
#include "string.h"

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

int CantidadLetras(ListaLetras l);

//recorre el binario y asigna TRUE/FALSE a cada letra dependiendo sea 1/0 el valor que le corresponde en el binario
void AsignarValor(ListaLetras letras, string binario);

void MostrarListaLetras(ListaLetras l);

void decimalToBinary(int n,int largo,string &result);

#endif // LISTA_LETRAS_H_INCLUDED
