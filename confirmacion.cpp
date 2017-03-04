#include "confirmacion.h"


void MostrarMensajeConfirmacion(Confirmacion c,string tag1,string tag2){
    switch(c){
        case TAUTO:
            printf("La expresion ");print(tag1);printf(" es una tautologia");
            break;
        case CONTI:
            printf("La expresion ");print(tag1);printf(" es una contingencia");
            break;
        case CONTRA:
            printf("La expresion ");print(tag1);printf(" es una contradiccion");
            break;
        case RESP:
            printf("La expresion ");print(tag1);printf(" respaldada correctamente en ");
            print(tag2);
            break;
        case SALUDO:
            break;

    }
    print(".\n");

}
