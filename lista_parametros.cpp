#include "lista_parametros.h"
#include "comandos.h"

void CrearLista(ListaParametros &l)
{
    l = NULL;
}

Boolean EsVacia(ListaParametros l){
    if(l == NULL)
      return TRUE;
    else
      return FALSE;
}

void DarParametro(ListaParametros l, int indice, string &s){
    int i = 0;
    ListaParametros aux;
    CrearLista(aux);
    aux = l;
    while((aux!=NULL) && (i < indice))
    {
        strcop(s,aux->parametro);
        aux = aux->sig;
        i++;
    }
    delete aux;
}

Error ValidarParametros(ListaParametros l,string comando){
    string p1,p2,p3;

    if(streq(comando,"ayuda\0")) {
        if(CantidadParametros(l) == 1){
            strcrear(p1);
            DarParametro(l,1,p1);
            if(ValidarComando(p1)== FALSE) {
                return COMANDO_INV;
            }else{
                return NO_ERR;
            }
        }else{
            return CANT_PARAM;
        }
    }else if(streq(comando,"atomica\0")){
        if(CantidadParametros(l) == 1){
            strcrear(p1);
            DarParametro(l,1,p1);
          if(EsLetra(p1) == FALSE)
            return TIPO_LETRA_INV;
          else
            return NO_ERR;
        }else{
           return CANT_PARAM;
        }
    }else if(streq(comando,"noatomica\0")){
        if(CantidadParametros(l) == 3){
           strcrear(p1);
           DarParametro(l,1,p1);
           if(EsLetra(p1) == FALSE){
              return TIPO_LETRA_INV;
           }else{
              strcrear(p2);
              DarParametro(l,2,p2);
              if(EsOperadorValido(p2) == TRUE){
                strcrear(p3);
                DarParametro(l,3,p3);
                if(EsLetra(p3) == TRUE){
                  return NO_ERR;
                }else{
                  return TIPO_LETRA_INV;
                }
              }else{
                return OPERADOR_INV;
              }
           }
        }else if (CantidadParametros(l) == 2){
           strcrear(p1);
           DarParametro(l,1,p1);
           if(EsOperadorValido(p1) == TRUE){
                strcrear(p2);
                DarParametro(l,2,p2);
                if(EsLetra(p2) == TRUE){
                  return NO_ERR;
                }else{
                  return TIPO_LETRA_INV;
                }
              }else{
                return OPERADOR_INV;
              }
          }else{
            return CANT_PARAM;
          }
    }else if(streq(comando,"respaldar\0")){
        if(CantidadParametros(l) == 2){
           strcrear(p1);
           DarParametro(l,1,p1);
           if(EsNumericoValido(p1) == TRUE){
               strcrear(p2);
               DarParametro(l,2,p2);
               if(EsNombreValido(p2) == TRUE)
                  return NO_ERR;
               else
                  return NOM_ARCH_INV;
            }else{
                return TIPO_NUM_INV;
            }

        }else{
          return CANT_PARAM;
        }

    }else if(streq(comando,"recuperar\0")){
        if(CantidadParametros(l) == 1){
            strcrear(p1);
            DarParametro(l,1,p1);
            if(EsNombreValido(p1) == TRUE)
              return NO_ERR;
            else
              return NOM_ARCH_INV;
        }else{
          return CANT_PARAM;
        }
    }else if(streq(comando,"letras\0")){
        if(CantidadParametros(l) == 1){
            strcrear(p1);
            DarParametro(l,1,p1);
            if(EsNumericoValido(p1) == TRUE)
              return NO_ERR;
            else
              return TIPO_NUM_INV;
        }else{
          return CANT_PARAM;
        }
    }else if(streq(comando,"evaluar\0")){
        if(CantidadParametros(l) == 1){
            strcrear(p1);
            DarParametro(l,1,p1);
            if(EsNumericoValido(p1) == TRUE)
              return NO_ERR;
            else
              return TIPO_NUM_INV;
        }else{
          return CANT_PARAM;
        }
    }else if(streq(comando,"salir\0")){
        if(CantidadParametros(l) != 0){
            return CANT_PARAM;
        }else{
            return NO_ERR;
        }
    }else if(streq(comando,"mostrar\0")){
        if(CantidadParametros(l) == 1){
          if(EsNumericoValido(p1) == TRUE)
              return NO_ERR;
            else
              return TIPO_NUM_INV;
        }else{
          return CANT_PARAM;
        }
    }else{
        return COMANDO_INV;
    }
}

int  CantidadParametros(ListaParametros l)
{
    int cantidad = 0;
    ListaParametros aux;
    CrearLista(aux);
    aux = l;
    while(aux != NULL)
    {
        cantidad++;
        aux = aux ->sig;
    }
    //delete aux;
    return cantidad;
}

Boolean EsNumericoValido(string parametro)
{
    Boolean es = TRUE;
    int i = 0;
    while((parametro[i]!='\0') && (es == TRUE))
    {
        switch(parametro[0])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        default:
            es = FALSE;
            break;

        }
        i++;
    }
    return es;

}

Boolean EsNombreValido(string parametro)
{
    Boolean es = FALSE;
    int i = 0;
    string aux;
    strcrear(aux);
    strsplit(parametro,'.',aux);
    if((streq(aux,".dat") == TRUE)||
            (streq(aux,".txt") == TRUE))
    {
        es = TRUE;
    }
    return es;
}

Boolean EsLetra(string parametro){
    return (Boolean)(((parametro[0]>='a' && parametro[0]<='z') || (parametro[0]>='A' && parametro[0]<='Z')) && parametro[1]=='\0');
}

Boolean EsOperadorValido(string parametro){

    switch(parametro[0]){
      case'&':
      case'|':
      case'!': return TRUE;
      default: return FALSE;
    }

}

void PrimerParametro (ListaParametros l,string &s) {
  strcop(s,l->parametro);
}

/* Precondición: lista NO vacía */
void Restoceder (ListaParametros &l) {
  ListaParametros aux;
  aux = l;
  l = l->sig;
  delete aux;
}

void InsFront (ListaParametros &l, string s) {
  ListaParametros aux;
  aux = new NodoParametros;
  strcop(aux->parametro,s);
  aux->sig = l;
  l = aux;
}

void InsUltimo (ListaParametros &l, string s){
  if (l == NULL)
    {
        l=new NodoParametros;
        strcop(l->parametro,s);
        l->sig=NULL;
    }
    else
        InsUltimo(l->sig,s);
}

void MostrarParametros(ListaParametros l){
  while(l!= NULL){
    print(l->parametro);
    l= l->sig;
  }

}
