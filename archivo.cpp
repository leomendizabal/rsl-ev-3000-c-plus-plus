#include"archivo.h"

void CrearArchivo(string nombre)
{
    FILE *f = fopen(nombre,"ab");
    fclose(f);
}

Boolean Existe (string nomArch)
{
    Boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}


void Bajar_Char(char c, FILE * f)
{
    fwrite(&c,sizeof(char),1,f);
}

void Levantar_Char(char &c, FILE * f)
{
    fread(&c,sizeof(char),1,f);
}

void Bajar_String (string s, FILE * f)
{
    int i=0;
    while(s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

void Levantar_String (string &s, FILE * f)
{
    int i=0;
    string saux=new char[MAX];
    fread(&saux[i],sizeof(char),1,f);
    while(!feof(f) && (saux[i]!='\0'))
    {
        i++;
        fread(&saux[i],sizeof(char),1,f);
    }
    strcop(s,saux);
    delete [] saux;
}

void Levantar_Int(int &i, FILE * f)
{
    fread(&i,sizeof(int),1,f);
}

void Bajar_Int(int i, FILE * f)
{
    fwrite (&i, sizeof (int), 1, f);
}

void Bajar_Arbol(ArbolComponentes abb,string nombreArch)
{

}
void Bajar_Arbol_Aux(ArbolComponentes abb,FILE *f)
{

}
void Levantar_Arbol(ArbolComponentes &abb,string nombreArch)
{

}
