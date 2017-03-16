#include"componente.h"

void CargarDato(Componente &c,int pos, char dato, TipoDato tipo){
    /*switch(tipo){
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
    c.valor= pos;*/
    CargarValor(c,pos);
    CargarTipo(c,tipo);
    CargarDatoTipo(c,dato);
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

void CargarValor(Componente &c, int valor){
  c.valor = valor;
}

void CargarTipo(Componente &c,int tipo){
   switch(tipo){
    case 0: c.tipo = LETRA; break;
    case 1: c.tipo = OPERADOR;  break;
    case 2: c.tipo = PARENTESIS;  break;
   }
}

void CargarDatoTipo(Componente &c,char dato){
  switch(c.tipo){
    case LETRA: c.dato.letra = dato; break;
    case OPERADOR:c.dato.operador = dato;  break;
    case PARENTESIS:c.dato.operador = dato;  break;
  }

}

TipoDato DarTipo(Componente c){
  return c.tipo;
}

int DarPosicion(Componente c)
{
    return c.valor;
}

int DarValor(Componente c){
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
    return (Boolean)(c.tipo == LETRA);
}

Boolean EsTipoOperador(Componente c){
    return (Boolean)(c.tipo == OPERADOR);
}

Boolean EsTipoParentesis(Componente c){
    return (Boolean)(c.tipo == PARENTESIS);
}

void AsignarPosicion(Componente c,int val)
{
   c.valor=val;
}

TipoDato IntATipoDato(int valor){
  switch(valor){
      case 0: return LETRA;break;
      case 1: return OPERADOR;break;
      case 2: return PARENTESIS;break;
      default: return LETRA;break;
  }

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
    BajarInt(DarValor(c),f);
    BajarInt(DarTipo(c),f);
    BajarChar(DarDato(c),f);
}

void LevantarComponente(Componente &c, FILE *f)
{
   int valor,tipo;
   char dato;
   LevantarInt(valor,f);
   LevantarInt(tipo,f);
   LevantarChar(dato,f);
   CargarDato(c,valor,dato,IntATipoDato(tipo));
}
