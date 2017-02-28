#include<stdlib.h>
#include "errores.h"

void MostrarMensajeError(Error e)
{
    system("cls");
    switch(e)
    {
    case 1:
         printf("Comando ingresado no es valido\n");
        break;
    case 2:
       printf("La cantidad de parametros es incorrecta\n");
        break;
    case 3:
       printf("El operador ingresado no es valido\n");
        break;
    case 4:
       printf("La expresion no existe\n");
        break;
    case 5:
       printf("El tipo de dato debe ser un numero\n");
        break;
    case 6:
       printf("El tipo de dato debe ser una letra\n");
        break;
    case 7:
       printf("El nombre del archivo no es valido\n");
        break;
    case 8:
       printf("No existe el archivo con ese nombre\n");
        break;

    }
}
