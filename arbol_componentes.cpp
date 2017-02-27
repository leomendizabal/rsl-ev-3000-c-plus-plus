#include "arbol_componentes.h"


void CrearVacio(ArbolComponentes &abb)
{
    abb=NULL;
}
void CrearArbol(ArbolComponentes &raiz, ArbolComponentes ramaIzq, ArbolComponentes ramaDer, Componente c)
{

    raiz=new NodoArb;    // Creo nueva memoria para guardar el componente
    if (EsTipoLetra(c))  // Si componente es letra , creo un arbol vacio con raiz c
    {
        raiz->info=c;
        raiz->Hizq=NULL;
        raiz->Hder=NULL;
    }
    else
       if (DarDato(c)=='!')   //Cuando el componente es un NOT
       {
          raiz->Hizq=NULL;          //  El hijo izquierdo de la raiz va a ser el parentesis "("
          int pos=1;
          char parenabierto='(';
          Componente parenizq;
          CargarDato(parenizq,pos,parenabierto,PARENTESIS);
          InsertarParentesisIzq(raiz,parenizq);
          raiz->info=c;                      // Inserto el operador como raiz
          ArbolComponentes CopiaRamaDer;
          CopiarArbol(CopiaRamaDer,ramaDer);  // Copio la rama derecha
          char parencerrado=')';
          Componente parender;
          CargarDato(parender,pos,parencerrado,PARENTESIS);
          InsertarParentesisDer(CopiaRamaDer,parender);    // Inserto el parentesis ")" como hoja derecha de la rama derecha
          raiz->Hder=CopiaRamaDer;              // El hijo derecho de la raiz va a ser la copia de la rama derecha
          AsignarPosicionOrdenado(raiz,pos);  // Ordeno cada componente del arbol con su pocision en orden (De menor a mayor)
       }
       else       // Cuando el componente es un OR o AND
       {
          int pos=1;
          char parenabierto='(';
          Componente parenizq;
          CargarDato(parenizq,pos,parenabierto,PARENTESIS);
          ArbolComponentes CopiaRamaIzq;
          CopiarArbol(CopiaRamaIzq,ramaIzq);
          InsertarParentesisIzq(CopiaRamaIzq,parenizq);  // Inserto el parentesis "(" como hoja izquierda de la rama izquierda
          raiz->info=c;                    // Inserto el operador como raiz
          ArbolComponentes CopiaRamaDer;
          CopiarArbol(CopiaRamaDer,ramaDer);    // Copio la rama derecha
          char parencerrado=')';
          Componente parender;
          CargarDato(parender,pos,parencerrado,PARENTESIS);
          InsertarParentesisDer(CopiaRamaDer,parender);  // Inserto el parentesis ")" como hoja derecha de la rama derecha
          raiz->Hizq=CopiaRamaIzq;
          raiz->Hder=CopiaRamaDer;            //Inserto como hijo izquierdo de la raiz a la copia de rama izquierda y como hijo derecho a la copia de rama derecha
          AsignarPosicionOrdenado(raiz,pos);  // Ordeno cada componente con su pocision en orden (De menor a mayor)
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
        if (EsTipoOperador(abb->info))
           {
            if (DarDato(abb->info)=='!')
                printf("! ");
            else
                if (DarDato(abb->info)=='|')
                    printf(" | ");
                else
                    printf(" & ");
           }
        else
             MostrarDato(abb->info);
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


void AsignarPosicionOrdenado(ArbolComponentes &abb, int &val)
{
    if (abb!=NULL)
    {
        AsignarPosicionOrdenado(abb->Hizq,val);
        AsignarPosicion(abb->info,val);
        val=val+1;
        AsignarPosicionOrdenado(abb->Hder,val);
    }
}

int CantidadDeNodos(ArbolComponentes abb){
   if(abb ==NULL){
      return 0;
   }else{
      return 1+ CantidadDeNodos(abb->Hizq)+CantidadDeNodos(abb->Hder);
   }
}



void BajarArbol(ArbolComponentes abb,string nombreArch)
{
  FILE * f = fopen (nombreArch, "wb");
  BajarArbolAux(abb,f);
  fclose (f);
}
void BajarArbolAux(ArbolComponentes abb,FILE *f)
{
   if (abb!= NULL)
    {
     BajarComponente(abb->info,f);
     BajarArbolAux(abb->Hizq, f);
     BajarArbolAux(abb->Hder, f);
    }
}
void LevantarArbol(ArbolComponentes &abb,string nombreArch)
{
  FILE * f = fopen (nombreArch, "rb");
  Componente buffer;
  LevantarComponente(buffer,f);
  while (!feof(f))
  {
     Insertar(abb,buffer);
     LevantarComponente(buffer,f);
  }
  fclose(f);
}
