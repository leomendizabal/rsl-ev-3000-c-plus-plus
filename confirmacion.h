#ifndef CONFIRMACION_H_INCLUDED
#define CONFIRMACION_H_INCLUDED
#include<stdio.h>
#include "string.h"

typedef enum{
        TAUTO,
        CONTI,
        CONTRA,
        RESP,
        SALUDO
 }Confirmacion;

void MostrarMensajeConfirmacion(Confirmacion c,string tag1,string tag2);

#endif // CONFIRMACION_H_INCLUDED
