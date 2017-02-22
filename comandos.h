#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "string.h"

//Retorna TRUE si el comando es correcto y FALSE  si es incorrecto
Boolean ValidarComando(string comando);

void ParsearComando(string entrada, string &comando,string &parametros);


#endif // COMANDOS_H_INCLUDED
