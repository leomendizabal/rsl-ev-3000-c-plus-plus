#ifndef ARBOL_COMPONENTES_H_INCLUDED
#define ARBOL_COMPONENTES_H_INCLUDED
#include "Componente.h"

typedef struct nodoA
{
    Componente info;
    nodoA *Hizq;
    nodoA *Hder;
} NodoArb;

typedef NodoArb *ArbolComponentes;

//crea el arbol vacio
void CrearVacio(ArbolComponentes &abb);

//crea un arbol, setea c como raiz y sus ramas izq/der con los subArboles ramaIzq/ramaDer.
void CrearArbol(ArbolComponentes &raiz, ArbolComponentes ramaIzq, ArbolComponentes ramaDer, Componente c);

//devuelve TRUE si es vacio
Boolean EsVacio(ArbolComponentes abb);

//devuelve el info de la raiz. PRECONDICION: abb !EsVacio
Componente DevolverRaiz(ArbolComponentes abb);

//devuelve el subArbol izquierdo de abb. PRECONDICION: abb !EsVacio
ArbolComponentes HijoIzq(ArbolComponentes abb);

//devuelve el subArbol derecho de abb. PRECONDICION: abb !EsVacio
ArbolComponentes HijoDer(ArbolComponentes abb);

//Inserta un nodo en el arbol, ordenado por su valor
void Insertar(ArbolComponentes &abb, Componente c);

//Inserta parentesis abierto como hoja izquierda PRECONDICION: abb !EsVacio
void InsertarParentesisIzq(ArbolComponentes &abb,Componente c);

//Inserta parentesis cerrado como hoja derecha PRECONDICION: abb !EsVacio
void InsertarParentesisDer(ArbolComponentes &abb,Componente c);

//Retorna TRUE si encuentra un nodo que contiene a letra
Boolean ExisteLetra(ArbolComponentes abb, char letra);

//Copia el contenido de abb a abbcopia
void CopiarArbol(ArbolComponentes &abbcopia,ArbolComponentes abb);

//Muestra el arbol en orden (de menor a mayor).
void MostrarArbol(ArbolComponentes abb);

//Elimina todos los nodos del arbol y lo deja vacio
void EliminarArbol(ArbolComponentes abb);

//Devuelve el valor maximo del arbol PRECONDICION: abb !EsVacio
int Maximo(ArbolComponentes abb);

//Asigna posiciones de los componentes ordenados de menor a mayor
void AsignarPosicionOrdenado(ArbolComponentes &abb, int &val);


#endif // ARBOL_COMPONENTES_H_INCLUDED
