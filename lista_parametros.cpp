#include "lista_parametros.h"

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
    int i = 1;
    while((l!=NULL) && (i < indice)) //mientras no sea el indice del parametro que quiero obtener
    {
        l = l->sig;                //paso al siguiente parametro
        i++;
    }
    if(indice == i && l != NULL){                   //si encontre el parametro con el indice que buscaba, lo copio a s
        strcop(s,l->parametro);
    }
}

void ValidarParametros(ListaParametros l,Comando cmd,string comando, Error &err, string &tag){
    string p1,p2,p3;
	switch(cmd){
        case AYU:
        	if(CantidadParametros(l) != 1){
              err =  CANT_PARAM;
	          strcop(tag,comando);
	        }
        	break;
        case ATO:
            if(CantidadParametros(l) == 1){
	          strcrear(p1);
	          DarParametro(l,1,p1);
	          if(EsLetra(p1) == FALSE){
	            err = TIPO_LETRA_INV;
	            strcop(tag,p1);
	          }else{
	            err = NO_ERR;
	            strcop(tag,comando);
	          }
	        }else{
	           err = CANT_PARAM;
	           strcop(tag,comando);
	        }
        	break;
        case NOATO:
            if(CantidadParametros(l) == 3){
	           strcrear(p1);
	           DarParametro(l,1,p1);
	           if(EsNumericoValido(p1) == FALSE){
	              err = TIPO_NUM_INV;
	              strcop(tag,p1);
	           }else{
	              strcrear(p2);
	              DarParametro(l,2,p2);
	              if(EsOperadorValido(p2) == TRUE){
	                strcrear(p3);
	                DarParametro(l,3,p3);
	                if(EsNumericoValido(p3) == TRUE){
	                  err = NO_ERR;
	                  strcop(tag,comando);
	                }else{
	                  err = TIPO_NUM_INV;
	                  strcop(tag,p3);
	                }
	              }else{
	                err = OPERADOR_INV;
	                strcop(tag,p2);
	              }
	           }
	       }else if (CantidadParametros(l) == 2){
	           strcrear(p1);
	           DarParametro(l,1,p1);
	           if(EsOperadorValido(p1) == TRUE){
	              strcrear(p2);
	              DarParametro(l,2,p2);
	              if(EsNumericoValido(p2) == TRUE){
	                 err = NO_ERR;
	                 strcop(tag,comando);
	              }else{
	                 err = TIPO_NUM_INV;
	                 strcop(tag,p2);
	              }
	           }else{
	              err = OPERADOR_INV;
	              strcop(tag,p1);
	           }
	         }else{
	            err = CANT_PARAM;
	            strcop(tag,comando);
	        }
        	break;
        case MOS:
        	if(CantidadParametros(l) == 1){
	          strcrear(p1);
	          DarParametro(l,1,p1);
	          if(EsNumericoValido(p1) == TRUE){
	             err = NO_ERR;
	             strcop(tag,comando);
	          }else{
	            err = TIPO_NUM_INV;
	            strcop(tag,p1);
	          }
	        }else{
	          err = CANT_PARAM;
	          strcop(tag,comando);
	        }
        	break;
        case EVA:
        	if(CantidadParametros(l) == 1){
	            strcrear(p1);
	            DarParametro(l,1,p1);
	            if(EsNumericoValido(p1) == TRUE){
	                err = NO_ERR;
	                strcop(tag,comando);
	            }else{
	                err = TIPO_NUM_INV;
	                strcop(tag,p1);
	            }
	        }else{
	          err = CANT_PARAM;
	          strcop(tag,comando);
	        }
        	break;
        case RES:
        	if(CantidadParametros(l) == 2){
	           strcrear(p1);
	           DarParametro(l,1,p1);
	           if(EsNumericoValido(p1) == TRUE){
	               strcrear(p2);
	               DarParametro(l,2,p2);
	               if(EsNombreValido(p2) == TRUE){
	                  err = NO_ERR;
	                  strcop(tag,comando);
	               }else{
	                  err = NOM_ARCH_INV;
	                  strcop(tag,p2);
	               }
	            }else{
	                err = TIPO_NUM_INV;
	                strcop(tag,p1);
	            }
	        }else{
	          err = CANT_PARAM;
	          strcop(tag,comando);
	        }
        	break;
        case REC:
        	if(CantidadParametros(l) == 1){
	            strcrear(p1);
	            DarParametro(l,1,p1);
	            if(EsNombreValido(p1) == TRUE){
	                err = NO_ERR;
	                strcop(tag,comando);
	            }else{
	                err = NOM_ARCH_INV;
	                strcop(tag,p1);
	            }
	        }else{
	          err = CANT_PARAM;
	          strcop(tag,comando);
	        }
        	break;
        case SAL:
        	if(CantidadParametros(l) != 0){
	            err = CANT_PARAM;
	            strcop(tag,comando);
	        }else{
	            err = NO_ERR;
	            strcop(tag,comando);
	        }
        	break;
        case LET:
        	if(CantidadParametros(l) == 1){
	            strcrear(p1);
	            DarParametro(l,1,p1);
	            if(EsNumericoValido(p1) == TRUE){
	                err = NO_ERR;
	                strcop(tag,comando);
	            }else{
	                err = TIPO_NUM_INV;
	                strcop(tag,p1);
	            }
	        }else{
	          err = CANT_PARAM;
	          strcop(tag,comando);
	        }
	        break;
	    default:
	    	err = COMANDO_INV;
        	strcop(tag,comando);

    }
    strdestruir(p1);
    strdestruir(p2);
    strdestruir(p3);
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
    while(strIsEnd(charAt(parametro,i) == FALSE) && (es == TRUE))
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
    char extDatArr[MAX] = ".dat\0";
    string extdat = extDatArr;
    char extTxtArr[MAX] = ".txt\0";
    string exttxt = extTxtArr;
    Boolean es = FALSE;
    if (EsAlfabetico(parametro)==TRUE)
    {
            string aux;
            strcrear(aux);
            strsplit(parametro,'.',aux);
            if((streq(aux,extdat) == TRUE)||
                           (streq(aux,exttxt) == TRUE))
            {
                 es = TRUE;
            }
            strdestruir(aux);
    }
    return es;
}

Boolean EsLetra(string parametro){
    return (Boolean)(((charAt(parametro,0)>='a' && charAt(parametro,0)<='z') || (charAt(parametro,0)>='A' && charAt(parametro,0)<='Z')) && charAt(parametro,1)=='\0');
}

Boolean EsOperadorValido(string parametro){

    switch(charAt(parametro,0)){
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

void EliminarLista(ListaParametros &l){
    if(l!=NULL)
    {
        EliminarLista(l->sig);
        strdestruir(l->parametro);
        delete l;
        l=NULL;
    }
}

void ParsearParametros(string parametros,ListaParametros &listaResultado){
    string param;
    string restoParam;

    strcrear(param);
    strcrear(restoParam);

    while(strlar(parametros)>0){
        //strcrear(param);
        strfirst(parametros, 0, ' ', param);            //obtiene el primer string hasta el espacio
        InsUltimo(listaResultado, param);              //inserta un nodo con el parametro a la lista
        strsplit(parametros, ' ', parametros);          //guarda en restoParam toda la cadena menos el primer string
        strcop(restoParam,parametros);
        strtrim(restoParam, parametros);
    }
    strdestruir(param);
    strdestruir(restoParam);

}
