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



