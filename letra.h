#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED

#include"boolean.h"

//Definido para  guardar cualquier caracter en una lista(Comando Letras)
typedef struct
{
    char letra;
    Boolean valor;

} InfoLetra;

//Carga la informacion de infoLetra
void CargarInfoLetra(InfoLetra &l,char c,Boolean val);
//Muestra la letra por pantalla
void MostrarLetra(InfoLetra l);
//Devuelve la letra de la estructura
char DarLetra(InfoLetra l);
//Devuelve el valor booleano de la estructura
Boolean DarValor(InfoLetra l);

int DarPotencia(int base, int potencia);

char intToChar(int numero);

#endif // LETRA_H_INCLUDED
