#include "lista_expresiones.h"



void CrearListaExpresiones(ListaExpresiones &l)
{
    l= NULL;
}

Boolean EsVacia(ListaExpresiones l){
    if(l == NULL)
      return TRUE;
    else
      return FALSE;
}

Expresion DarExpresion(ListaExpresiones l,int indice){
    int i = -1;
    ListaExpresiones aux = l;
    while((aux!= NULL) && (i != indice)){
      i = aux->ex.indice;
      aux = aux->sig;
    }
    if(i == indice){
      return aux->ex;
    }
    delete aux;
}

Expresion PrimerExpresion (ListaExpresiones l) {
  return l->ex;
}
/* Precondición: lista NO vacía */
void Restoceder (ListaExpresiones &l) {
  ListaExpresiones aux;
  aux = l;
  l = l->sig;
  delete aux;
}
void InsFront (ListaExpresiones &l, Expresion e) {
  ListaExpresiones aux;
  aux = new NodoListaE;
  aux->ex = e;
  aux->sig = l;
  l = aux;
}
