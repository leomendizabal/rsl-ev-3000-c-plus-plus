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
    Boolean terminar = FALSE;

    /*while ((EsVacia(l) == FALSE) && (indice != DarIndice(l->ex))){
        l = l->sig;
    }
    return EsVacia(l);*/
    while((aux != NULL) && !terminar){
      if(indice != DarIndice(aux->ex))
        aux = aux->sig;
      else{
        i = DarIndice(aux->ex);
        terminar = TRUE;
      }
    }

    return i==indice ? TRUE : FALSE;

}

void DarExpresion(ListaExpresiones l,int indice, Expresion &e){
    /*while ((EsVacia(l) == FALSE) && (indice != DarIndice(l->ex))){
        l = l->sig;
    }
    if (EsVacia(l) == FALSE)
          e = l->ex;*/

    ListaExpresiones aux = l;
    Boolean terminar = FALSE;

    while((aux != NULL) && !terminar){
      if(indice != aux->ex.indice)
        aux = aux->sig;
      else{
        e = aux->ex;
        terminar = TRUE;
      }
    }
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
  aux = l;

  if(aux == NULL){
    return 0;
  }else{
    while(EsVacia(aux->sig) == FALSE){
      aux = aux->sig;
    }
  }

  return DarIndice(aux->ex);

}

void MostrarListaExpresiones(ListaExpresiones l){
    ListaExpresiones aux;
    CrearLista(aux);
    aux = l;

    //printf("Lista de indices de las expresiones: \n");
    while(EsVacia(aux) == FALSE){
      MostrarExpresion(aux->ex);
      aux= aux->sig;
    }

    delete aux;
}

void EliminarLista(ListaExpresiones &l){
    if(l!=NULL)
    {
        EliminarLista(l->sig);
        EliminarArbol(DarArbol(l->ex));
        delete l;
        l=NULL;
    }
}
