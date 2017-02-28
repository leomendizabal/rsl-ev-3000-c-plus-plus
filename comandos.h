#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "lista_expresiones.h"
#include "lista_parametros.h"
#include "string.h"

//Retorna TRUE si el comando es correcto y FALSE  si es incorrecto
Boolean ValidarComando(string comando);

void ParsearComando(string entrada, string &comando,string &parametros);

void ParsearParametros(string parametros,ListaParametros &listaResultado);

void ComandoAyuda(string  comando);

//crea una expresion atomica y la inserta al final de la lista de expresiones
void ComandoAtomica(ListaExpresiones &l, string p);

void ComandoSalir(ListaExpresiones &l);

//Muestra la expresion de la lista l , cuyo indice esta determinado en el parametro p
void ComandoMostrar(ListaExpresiones l,int indice);


void ComandoLetras(ListaExpresiones l, int indice);

#endif // COMANDOS_H_INCLUDED
