#include "lista_letras.h"



void CrearLista(ListaLetras &l){

  l = NULL;
}

Boolean EsVacia(ListaLetras l){
  Boolean vacia = FALSE;
  if(l == NULL){
    vacia = TRUE;
  }
  return vacia;
}

Boolean DarValorLetra(ListaLetras l,char s){
  Boolean valor = FALSE;
  while ((EsVacia(l) == FALSE) && (DarLetra(l->info) != s)){
    l=l->sig;
  }
  if(DarLetra(l->info) == s){
    valor = DarValor(l->info);
  }
  return valor;
}

Boolean ExisteLetra(ListaLetras l,char letra){
  Boolean valor = FALSE;
  while((EsVacia(l) == FALSE) && (DarLetra(l->info) != letra)){
    l=l->sig;
  }
  if(DarLetra(l->info) == letra){
    valor = TRUE;
  }
  return valor;
}

void Restoceder (ListaLetras &l){
    ListaLetras aux;
    aux = l;
    l = l->sig;
    delete aux;

}

void InsFront (ListaLetras &l, InfoLetra info){
    ListaLetras aux;
    aux = new NodoLista;
    aux->info = info;
    aux->sig = l;
    l = aux;

}

void InsUltimo (ListaLetras &l, InfoLetra info){
  if (l == NULL)
    {
        l=new NodoLista;
        l->info = info;
        l->sig = NULL;
    }
    else
        InsUltimo(l->sig,info);

}
