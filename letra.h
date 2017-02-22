#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED

//Definido para  guardar cualquier caracter en una lista(Comando Letras)
typedef struct
{
    char letra;
    Boolean valor;

} infoLetra;

//Carga la informacion de infoLetra
void CargarInfoLetra(infoLetra &l,char l,Boolean val);
//Muestra la letra por pantalla 
Void MostrarLetra(infoLetra l);
//Devuelve la letra de la estructura
char DarLetra(infoLetra l);
//Devuelve el valor booleano de la estructura
Boolean DarValor(infoLetra l);


#endif // LETRA_H_INCLUDED
