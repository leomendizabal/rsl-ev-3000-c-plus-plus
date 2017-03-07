#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "lista_expresiones.h"
#include "lista_parametros.h"
#include "lista_letras.h"
#include "string.h"
#include "archivo.h"

#include "errores.h"
#include "confirmacion.h"


//Retorna TRUE si el comando es correcto y FALSE  si es incorrecto
Comando ValidarComando(string comando);

void ParsearComando(string entrada, string &comando,string &parametros);

void ParsearParametros(string parametros,ListaParametros &listaResultado);

void ComandoAyuda(Comando comando);

//crea una expresion atomica y la inserta al final de la lista de expresiones
void ComandoAtomica(ListaExpresiones &l, string p);

void ComandoSalir(ListaExpresiones &le,ListaParametros &lp);

//Muestra la expresion de la lista l , cuyo indice esta determinado en el parametro p
void ComandoMostrar(ListaExpresiones l,int indice);

void ComandoLetras(ListaExpresiones l, int indice);

void ComandoNoAtomica(ListaExpresiones &le,int cant,string p1,string p2,string p3);

void ComandoRespaldar(ListaExpresiones le,int indice,string nombreArch);

void ComandoRecuperar(ListaExpresiones &le,string nombreArch);

void ComandoEvaluar(ListaExpresiones le,int indice);

int CantidadParametrosComando(Comando comando);


#endif // COMANDOS_H_INCLUDED
