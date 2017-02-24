#include "errores.h"

void MostrarMensajeError(Error e)
{

    switch(e)
    {
    case 1:
         printf("COMANDO_INV");
        break;
    case 2:
       printf("CANT_PARAM");
        break;
    case 3:
       printf("OPERADOR_INV");
        break;
    case 4:
       printf("NO_EXISTE_EXP");
        break;
    case 5:
       printf("TIPO_NUM_INV");
        break;
    case 6:
       printf("TIPO_LETRA_INV");
        break;
    case 7:
       printf("NOM_ARCH_INV");
        break;
    case 8:
       printf("ARCH_NO_EXISTE");
        break;

    }


}
