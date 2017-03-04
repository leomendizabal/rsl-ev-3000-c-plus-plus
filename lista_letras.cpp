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

  while((EsVacia(l) == FALSE) && !valor){
    valor = (Boolean)(DarLetra(l->info) == letra);
    l=l->sig;
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

void MostrarListaLetras(ListaLetras l){
    while(l!= NULL){
        MostrarLetra(l->info);
        l= l->sig;
    }
}

void decimalToBinary(int n,int largo,string &result) {
 int remainder;
 while(n != 0 && strlar(result)!= largo) {
     remainder = n%2;
     n = n/2;
     straddchar(result,intToChar(remainder));
 }
 for(int i= strlar(result); strlar(result) < largo;i++ )
   straddchar(result,intToChar(0));
}
