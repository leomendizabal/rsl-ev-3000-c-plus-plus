#include "arbol_componentes.h"


void CrearVacio(ArbolComponentes &abb)
{
    abb=NULL;
}
void CrearArbol(ArbolComponentes &raiz, ArbolComponentes ramaIzq, ArbolComponentes ramaDer, Componente c)
{
    raiz=new NodoArb;
    raiz->info=c;
    raiz->Hizq=ramaIzq;
    raiz->Hder=ramaDer;

}
Boolean EsVacio(ArbolComponentes abb)
{
    Boolean esVacio = FALSE;
    if(abb==NULL)
        esVacio = TRUE;

    return esVacio;
}
Componente DevolverRaiz(ArbolComponentes abb)
{
    return abb->info;
}
ArbolComponentes HijoIzq(ArbolComponentes abb)
{
   return abb->Hizq;
}
ArbolComponentes HijoDer(ArbolComponentes abb)
{
   return abb->Hder;
}
void Insertar(ArbolComponentes &abb, Componente c)
{
   if (abb == NULL)
       {
           abb = new NodoArb;
           abb->info = c;
           abb->Hizq = NULL;
           abb->Hder = NULL;
       }
    else
        if (DarPosicion(c)<DarPosicion(abb->info))
              Insertar(abb->Hizq,c);
        else
              Insertar(abb->Hder,c);

}
Boolean ExisteLetra(ArbolComponentes abb, char letra)
{
  if (abb = NULL)
     return FALSE;
  else
       if (EsTipoLetra(abb->info) && (DarDato(abb->info)==letra))
           return TRUE;
       else
           return (Boolean) (ExisteLetra(abb->Hizq,letra) ||  ExisteLetra(abb->Hder,letra));
}
void CopiarArbol(ArbolComponentes &abbcopia,ArbolComponentes abb)
{
  if (abb!=NULL)
  {
      abbcopia=new NodoArb;
      abbcopia->info=abb->info;
      abbcopia->Hizq=NULL;
      abbcopia->Hder=NULL;
      CopiarArbol(abbcopia->Hizq,abb->Hizq);
      CopiarArbol(abbcopia->Hder,abb->Hder);
  }
}
void MostrarArbol(ArbolComponentes abb)
{
  if (abb!=NULL)
  {
        MostrarArbol(abb->Hizq);
        MostrarDato(abb->info);
        if (EsTipoParentesis(abb->info)==FALSE)
              printf(" ");
        MostrarArbol(abb->Hder);
  }
}
void EliminarArbol(ArbolComponentes abb)
{
  if (abb!=NULL)
  {
        EliminarArbol(abb->Hizq);
        EliminarArbol(abb->Hder);
        delete abb;
        abb=NULL;
  }
}
