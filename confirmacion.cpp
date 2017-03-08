#include "confirmacion.h"


void MostrarMensajeConfirmacion(Confirmacion c,int tag1,string tag2){
    switch(c){
        case TAUTO:
            printf("La expresion %d es una tautologia",tag1);
            break;
        case CONTI:
            printf("La expresion %d es una contingencia",tag1);
            break;
        case CONTRA:
            printf("La expresion %d es una contradiccion",tag1);
            break;
        case RESP:
            printf("La expresion %d respaldada correctamente en ",tag1);
            print(tag2);
            break;
        case SALUDO:
            printf("Hasta la proxima");
            break;

    }
    printf(".\n");

}
