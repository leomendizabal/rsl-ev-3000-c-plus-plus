#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "expresion.h"
#include <stdio.h>


//Crear archivos.

Boolean Existe(string nombrArch);

void CrearArchivo(string nombre);

void Bajar_Char (char c, FILE * f);

void Levantar_Char (char &c, FILE * f);


void Bajar_String (string s, FILE * f);

void Levantar_String (string &s, FILE * f);

void Levantar_Int(int &i, FILE * f);

void Bajar_Int(int i, FILE * f);

void Bajar_Arbol(ArbolComponentes abb,string nombreArch);

void Bajar_Arbol_Aux(ArbolComponentes abb,FILE *f);

void Levantar_Arbol(ArbolComponentes &abb,string nombreArch);


#endif // ARCHIVO_H_INCLUDED
