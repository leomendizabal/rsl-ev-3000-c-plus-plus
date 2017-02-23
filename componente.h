#ifndef COMPONENTE_H_INCLUDED
#define COMPONENTE_H_INCLUDED
#include "string.h"

//Tipo de datos
typedef enum {LETRA,OPERADOR,PARENTESIS} TipoDato;

//componente de una expresion
typedef struct
{
    int valor;
    TipoDato tipo;
    union
    {
        char operador;
        char letra;
        char parentesis;
    } dato;

} Componente;

void CargarDato(Componente &c,int pos, char dato, TipoDato tipo);

char DarDato(Componente c);

int DarPosicion(Componente c);

void MostrarDato(Componente c);

Boolean EsTipoLetra(Componente c);

Boolean EsTipoOperador(Componente c);

Boolean EsTipoParentesis(Componente c);


#endif // COMPONENTE_H_INCLUDED
