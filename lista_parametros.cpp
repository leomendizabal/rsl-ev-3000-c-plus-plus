#include "lista_parametros.h"


void CrearLista(ListaParametros &l)
{
    l= NULL;
}

void DarParametro(ListaParametros l, int indice, string &s)
{
    int i = indice;
    while((l!=NULL) && (i >= 0))
    {
        strcop(s,l->parametro);
        l = l->sig;
    }
}

Error ValidarParametros(ListaParametros l,string comando)
{
    if(streq(comando,"ayuda"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }
    else if(streq(comando,"atomica"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }
    else if(streq(comando,"noatomica"))
    {
        if((CantidadParametros(l) == 3) ||(CantidadParametros(l) == 2))
        {

        }

    }
    else if(streq(comando,"respaldar"))
    {
        if(CantidadParametros(l) == 2)
        {

        }

    }
    else if(streq(comando,"recuperar"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }
    else if(streq(comando,"letras"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }
    else if(streq(comando,"evaluar"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }
    else if(streq(comando,"salir"))
    {
        if(CantidadParametros(l) == 0)
        {

        }

    }
    else if(streq(comando,"mostrar"))
    {
        if(CantidadParametros(l) == 1)
        {

        }

    }




}

int  CantidadParametros(ListaParametros l)
{
    int cantidad = 0;
    while(l != NULL)
    {
        cantidad++;
        l = l ->sig;
    }
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
