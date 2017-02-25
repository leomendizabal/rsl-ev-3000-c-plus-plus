#include "arbol_componentes.h"


void CrearVacio(ArbolComponentes &abb)
{
    abb=NULL;
}
void CrearArbol(ArbolComponentes &raiz, ArbolComponentes ramaIzq, ArbolComponentes ramaDer, Componente c)
{

    raiz=new NodoArb;
    if (EsTipoLetra(c))
    {
        raiz->info=c;
        raiz->Hizq=NULL;
        raiz->Hder=NULL;
    }
    else
       if (DarDato(c)=='!')
       {
          raiz->Hizq=NULL;
          //raiz->Hder=NULL;
          int pos=1;
          char parenabierto='(';
          Componente parenizq;
          CargarDato(parenizq,pos,parenabierto,PARENTESIS);
          InsertarParentesisIzq(raiz,parenizq);
          IncrementarValor(c,Maximo(raiz->Hizq)+1);
          raiz->info=c;
          ArbolComponentes CopiaRamaDer;
          CopiarArbol(CopiaRamaDer,ramaDer);
          IncrementarValoresArbol(CopiaRamaDer,DarPosicion(raiz->info));
          pos=Maximo(CopiaRamaDer)+1;
          char parencerrado=')';
          Componente parender;
          CargarDato(parender,pos,parencerrado,PARENTESIS);
          InsertarParentesisDer(CopiaRamaDer,parender);
          raiz->Hder=CopiaRamaDer;
       }
       else
       {

       }

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
void InsertarParentesisIzq(ArbolComponentes &abb,Componente c)
{
    if (abb->Hizq==NULL)
    {
           abb = new NodoArb;
           abb->info = c;
           abb->Hizq = NULL;
           abb->Hder = NULL;
    }
    else
        InsertarParentesisIzq(abb->Hizq,c);
}
void InsertarParentesisDer(ArbolComponentes &abb,Componente c)
{
  if (abb->Hder==NULL)
    {
           abb = new NodoArb;
           abb->info = c;
           abb->Hizq = NULL;
           abb->Hder = NULL;
    }
    else
        InsertarParentesisDer(abb->Hder,c);
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
int Maximo(ArbolComponentes abb)
{
   while (abb->Hder != NULL)
        abb= abb->Hder;
   return (DarPosicion(abb->info));
}

void IncrementarValoresArbol(ArbolComponentes abb, int val)
{
  if (abb!=NULL)
  {
     IncrementarValor(abb->info,val);
     IncrementarValoresArbol(abb->Hizq,val);
     IncrementarValoresArbol(abb->Hder,val);
  }
}

int CantidadDeNodos(ArbolComponentes abb){
   if(abb ==NULL){
      return 0;
   }else{
      return 1+ CantidadDeNodos(abb->Hizq)+CantidadDeNodos(abb->Hder);
   }
}



void BajarArbol(ArbolComponentes abb,FILE *f)
{

}
void BajarArbolAux(ArbolComponentes abb,FILE *f)
{

}
void LevantarArbol(ArbolComponentes &abb,FILE *f)
{

}
