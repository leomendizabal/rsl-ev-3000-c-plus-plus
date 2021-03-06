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

typedef enum
{   AYU,
	ATO,
	NOATO,
	MOS,
	RES,
	REC,
	LET,
	EVA,
	SAL,
	INV
}Comando;

typedef NodoParametros *ListaParametros;

void CrearLista(ListaParametros &l);

Boolean EsVacia(ListaParametros l);

void DarParametro(ListaParametros l, int indice, string &s);

void ValidarParametros(ListaParametros l,Comando cmd,string comando, Error &err, string &tag);

int  CantidadParametros(ListaParametros l);

Boolean EsNumericoValido(string parametro);

Boolean EsNombreValido(string parametro);

//Valida si es de largo uno y es un char [A-a,Z-z]
Boolean EsLetra(string parametro);

Boolean EsOperadorValido(string parametro);

void PrimerParametro (ListaParametros l,string &s);

void Restoceder (ListaParametros &l);

void InsFront (ListaParametros &l, string s);

void InsUltimo (ListaParametros &l, string s);

void MostrarParametros(ListaParametros l);

void EliminarLista(ListaParametros &l);

void ParsearParametros(string parametros,ListaParametros &listaResultado);

#endif // LISTA_PARAMETROS_H_INCLUDED
