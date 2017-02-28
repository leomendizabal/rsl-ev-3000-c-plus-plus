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

int DarValor(Componente c);

TipoDato DarTipo(Componente c);

int DarPosicion(Componente c);

void MostrarDato(Componente c);

void CargarValor(Componente &c, int valor);

void CargarTipo(Componente &c,int tipo);

void CargarDatoTipo(Componente &c,char dato);

Boolean EsTipoLetra(Componente c);

Boolean EsTipoOperador(Componente c);

Boolean EsTipoParentesis(Componente c);

void IncrementarValor(Componente &c,int val);

TipoDato IntATipoDato(int valor);

//Para archivos

void BajarChar (char c, FILE * f);

void LevantarChar (char &c, FILE * f);

void LevantarInt(int &i, FILE * f);

void BajarInt(int i, FILE * f);

void BajarComponente(Componente c, FILE *f);

void LevantarComponente(Componente &c, FILE *f);

void AsignarPosicion(Componente c,int val);


#endif // COMPONENTE_H_INCLUDED
