#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "expresion.h"
#include <stdio.h>


//Crear archivos.

Boolean Existe(string nombrArch);

void CrearArchivo(string nombre);

void Bajar_String (string s, FILE * f);

void Levantar_String (string &s, FILE * f);


#endif // ARCHIVO_H_INCLUDED
