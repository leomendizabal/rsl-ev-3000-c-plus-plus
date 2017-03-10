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





