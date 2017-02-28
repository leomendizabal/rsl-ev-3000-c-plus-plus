#include "errores.h"

void MostrarMensajeError(Error e)
{
    system("cls");

    switch(e)
    {
    case COMANDO_INV:
         printf("Comando ingresado no es valido\n");
        break;
    case CANT_PARAM:
       printf("La cantidad de parametros es incorrecta\n");
        break;
    case OPERADOR_INV:
       printf("El operador ingresado no es valido\n");
        break;
    case NO_EXISTE_EXP:
       printf("La expresion no existe\n");
        break;
    case TIPO_NUM_INV:
       printf("El tipo de dato debe ser un numero\n");
        break;
    case TIPO_LETRA_INV:
       printf("El tipo de dato debe ser una letra\n");
        break;
    case NOM_ARCH_INV:
       printf("El nombre del archivo no es valido\n");
        break;
    case ARCH_NO_EXISTE:
       printf("No existe el archivo con ese nombre\n");
        break;

    }
}
