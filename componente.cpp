#include"componente.h"

void CargarDato(Componente &c,int pos, char dato, TipoDato tipo){
    switch(tipo){
        case LETRA:
            c.dato.letra = dato;
            break;
        case OPERADOR:
            c.dato.operador = dato;
            break;
        case PARENTESIS:
            c.dato.parentesis = dato;
            break;
        default:
            break;
    }
    c.tipo = tipo;
    c.valor= pos;
}

char DarDato(Componente c){
    char resultado;

    switch(c.tipo){
        case LETRA:
            resultado = c.dato.letra;
            break;
        case OPERADOR:
            resultado = c.dato.operador;
            break;
        case PARENTESIS:
            resultado = c.dato.parentesis;
            break;
        default:
            break;
    }

    return resultado;
}

int DarPosicion(Componente c)
{
    return c.valor;
}

void MostrarDato(Componente c){
    char resultado;
    switch(c.tipo){
        case LETRA:
            resultado = c.dato.letra;
            break;
        case OPERADOR:
            resultado = c.dato.operador;
            break;
        case PARENTESIS:
            resultado = c.dato.parentesis;
            break;
        default:
            break;
    }

    printf("%c", resultado);
}

Boolean EsTipoLetra(Componente c){
    return (Boolean)(c.tipo == 0);
}

Boolean EsTipoOperador(Componente c){
    return (Boolean)(c.tipo == 1);
}

Boolean EsTipoParentesis(Componente c){
    return (Boolean)(c.tipo == 2);
}

void IncrementarValor(Componente &c,int val)
{
   c.valor=c.valor+val;
}


void BajarChar(char c, FILE * f)
{
    fwrite(&c,sizeof(char),1,f);
}

void LevantarChar(char &c, FILE * f)
{
    fread(&c,sizeof(char),1,f);
}

void LevantarInt(int &i, FILE * f)
{
    fread(&i,sizeof(int),1,f);
}

void BajarInt(int i, FILE * f)
{
    fwrite (&i, sizeof (int), 1, f);
}

void BajarComponente(Componente c, FILE *f){

}

