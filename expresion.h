#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include "arbol_componentes.h"

//Expresion corresponde a un struct con un arbol y el numero de expresion
typedef struct
{
    ArbolComponentes arb;
    int indice;
} Expresion;


#endif // EXPRESION_H_INCLUDED
