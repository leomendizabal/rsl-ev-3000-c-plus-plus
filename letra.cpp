#include "letra.h"

//Carga la informacion de infoLetra
void CargarInfoLetra(InfoLetra &l,char c,Boolean val){
    l.letra = c;
    l.valor = val;
}
//Muestra la letra por pantalla
void MostrarLetra(InfoLetra l){
    printf("%c",l.letra);
    //Mostrar(l.valor);
}
//Devuelve la letra de la estructura
char DarLetra(InfoLetra l){
  return l.letra;
}
//Devuelve el valor booleano de la estructura
Boolean DarValor(InfoLetra l){
  return l.valor;
}
