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
  Boolean existe = FALSE;

  while((EsVacia(l) == FALSE) && !existe){
    existe = (Boolean)(DarLetra(l->info) == letra);
    l=l->sig;
  }

  return existe;
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

int CantidadLetras(ListaLetras l){
    int cantidad = 0;

    while(EsVacia(l) == FALSE){
        cantidad++;
        l=l->sig;
    }

    return cantidad;
}

void AsignarValor(ListaLetras letras, string binario){
     int i = 0;
     Boolean valorProposicional = FALSE;

     while(EsVacia(letras) == FALSE && binario[i] != '\0'){
        valorProposicional = binario[i] == '0' ? FALSE : TRUE;
        CargarInfoLetra(letras->info, DarLetra(letras->info), valorProposicional);
        i++;
        letras=letras->sig;
    }
}

void MostrarListaLetras(ListaLetras l){
    while(l!= NULL){
        MostrarLetra(l->info);
        printf(" ");
        Mostrar(DarValor(l->info));
        printf("\n");
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
