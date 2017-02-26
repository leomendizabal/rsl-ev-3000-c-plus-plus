#include "lista_expresiones.h"



void CrearLista(ListaExpresiones &l)
{
    l= NULL;
}

Boolean EsVacia(ListaExpresiones l){
    if(l == NULL)
      return TRUE;
    else
      return FALSE;
}

Boolean ExisteExpresion(ListaExpresiones l,int indice){
    int i = 0;
    ListaExpresiones aux = l;
    while((aux!= NULL) && (i != indice)){
      i = aux->ex.indice;
      aux = aux->sig;
    }
    delete aux;
    return i==indice ? TRUE : FALSE;
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
/* Precondici�n: lista NO vac�a */
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


void InsUltimo (ListaExpresiones &l, Expresion e){
  if (l == NULL)
    {
        l=new NodoListaE;
        l->ex = e;
        l->sig = NULL;
    }
    else
        InsUltimo(l->sig,e);
}

int UltimoIndice(ListaExpresiones l){
  ListaExpresiones aux;
  CrearLista(aux);

  while(EsVacia(l->sig) == FALSE){
    l= l->sig;
  }

  return DarIndice(l->ex);

}
