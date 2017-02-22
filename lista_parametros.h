#ifndef LISTA_PARAMETROS_H_INCLUDED
#define LISTA_PARAMETROS_H_INCLUDED
#include "string.h"
#include "errores.h"
//Tipo lista de parametros
typedef struct nodoP
{
    string parametro;
    nodoP *sig;
} NodoParametros;


typedef NodoParametros *ListaParametros;

void CrearLista(ListaParametros &l);

void DarParametro(ListaParametros l, int indice, string &s);

Error ValidarParametros(ListaParametros l,string comando);

int  CantidadParametros(ListaParametros l);

Boolean EsNumericoValido(string parametro);

Boolean EsNumericoValido(string parametro);

Boolean EsNombreValido(string parametro);


#endif // LISTA_PARAMETROS_H_INCLUDED
