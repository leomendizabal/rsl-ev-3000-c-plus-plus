#include "errores.h"

void MostrarMensajeError(Error e, string etiqueta,int valor)
{

    switch(e)
    {
    case COMANDO_INV:
        printf("El comando "); print(etiqueta); printf(" ingresado no es valido");
        break;
    case CANT_PARAM:
        printf("La cantidad de parametros para el comando ");print(etiqueta); printf(" debe ser: ");
        //int cant = CantidadParametrosComando(etiqueta);
        if (valor == 5){
            printf("%d",2);printf(" o ");printf("%d",3);
        }else{
             printf("%d",valor);
        }
        break;
    case OPERADOR_INV:
       printf("El operador ");print(etiqueta);printf(" no es valido");
        break;
    case NO_EXISTE_EXP:
       printf("La expresion ");print(etiqueta);printf(" no existe en memoria");
       break;
    case TIPO_NUM_INV:
        printf("El parametro ");print(etiqueta);printf(" no es un numero");
        break;
    case TIPO_LETRA_INV:
       printf("El parametro ");print(etiqueta);printf(" no es una letra");
        break;
    case NOM_ARCH_INV:
       printf("El nombre ");print(etiqueta);printf(" no es valido para un archivo");
        break;
    case ARCH_NO_EXISTE:
       printf("No existe el archivo con nombre ");print(etiqueta);
       break;
    default:break;
    }
    printf(".\n");
}
