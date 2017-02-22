#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED
#include<stdio.h>


typedef enum { NO_ERR,
               COMANDO_INV,
               CANT_PARAM,
               OPERADOR_INV,
               NO_EXISTE_EXP,
               TIPO_NUM_INV,
               TIPO_LETRA_INV,
               NOM_ARCH_INV,
               ARCH_NO_EXISTE
              } Error ;

void MostrarMensajeError(Error e);

#endif // ERRORES_H_INCLUDED
