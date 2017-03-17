#include "string.h"

void strcrear(string &s)
{
    s=new char[1];
    s[0]='\0';
}
void strdestruir(string &s)
{
    delete[]s;
    s=NULL;
}
int strlar(string s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void strcop(string &s1,string s2)
{
    int n,i=0;
    delete[]s1;
    n=strlar(s2)+1;
    s1=new char[n];
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
}
void scan(string &s)
{
    int i=0;
    char c;
    string saux=new char[MAX];
    fflush(stdin);
    scanf("%c",&c);
    while(c!='\n'&& i<MAX-1)
    {
        saux[i]=c;
        i++;
        scanf("%c",&c);
    }
    saux[i]='\0';
    strcop(s,saux);
    strdestruir(saux);
}
void strcon(string &s1,string s2)
{
    string saux;
    int lar=strlar(s1)+strlar(s2)+1;
    int i=0;
    saux=new char[lar];
    while(s1[i]!='\0'&& i<MAX-1)
    {
        saux[i]=s1[i];
        i++;
    }
    int j=0;
    while(s2[j]!='\0'&& i<MAX-1)
    {
        saux[i]=s2[j];
        j++;
        i++;
    }
    saux[i]='\0';
    strcop(s1,saux);
    strdestruir(saux);
}
void strswp(string &s1,string &s2)
{
    string saux;
    strcrear(saux);
    strcop(saux,s1);
    strcop(s1,s2);
    strcop(s2,saux);
}
void print(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c",s[i]);
        i++;
    }
}
Boolean strmen(string s1,string s2)
{
    int i=0;
    Boolean Esmenor=FALSE,entro=FALSE;
    while(!Esmenor && s1[i]!='\0' && s2[i]!='\0')
    {
        if (s1[i]<s2[i])
        {
            Esmenor=TRUE;
            entro=TRUE;
        }
        else
            i++;
    }
    if (Esmenor && entro)
        Esmenor=TRUE;
    else
        Esmenor=FALSE;
    return Esmenor;
}
Boolean streq(string s1,string s2)
{
    int i=0;
    Boolean iguales=TRUE;
    while(iguales && s1[i]!='\0' && s2[i]!='\0')
    {
        if (s1[i]!=s2[i])
            iguales=FALSE;
        else
            i++;
    }
    if (s1[i]!=s2[i])
        iguales=FALSE;
    return iguales;
}

//Retorna retorna la un sub string desde un char dado  hacia el final.
void strsplit(string s1, char c, string &s2){
  int i = 0;
  string aux = new char[MAX];
  while((s1[i]!='\0') && (s1[i] != c)){
    i++;
  }
  if(s1[i] == c){
    int j = 0;
    while(s1[i]!= '\0'){
      aux[j]=s1[i];
      i++;
      j++;
    }
    aux[j] = '\0';
  }else{
    aux[0] = '\0';
  }
  strcop(s2,aux);
  strdestruir(aux);

}


//Retorna un sub string desde index a un char dado.
void strfirst(string s1, int index, char c, string &s2){

  int i = index;
  string aux = new char [MAX];
  while((s1[i]!='\0') && (s1[i] != c)){
    aux[i] = s1[i];
    i++;
  }
  aux[i] = '\0';
  strcop(s2,aux);
  strdestruir(aux);
}

//Quita todos los espacios del principio
void strtrim(string s1, string &s2){
  int i = 0;
  int j = 0;
  string aux = new char [MAX];

  while(s1[i] == ' '){
    i++;
  }

  while(s1[i] != ' ' && s1[i] != '\0'){
    aux[j] = s1[i];
    j++;
    i++;
  }
  aux[j] = '\0';
  strcop(s2,aux);
  strdestruir(aux);
}

int strToInt(string s){
    int resultado = 0;
    int largo = strlar(s);

    for(int i=0; i<largo; i++){
        resultado = resultado * 10 + (s[i] - '0');
    }

    return resultado;
}

void strToLowerCase(string &s){
    int largo = strlar(s);

    for(int i=0; i<largo; i++){
        if(s[i]>= 65 && s[i]<=90)
            s[i] += 32;
    }
}
 //precondicion: el indice es menor al largo del string
char charAt(string s, int index){
    return s[index];
}

void straddchar(string &s,char c){
    int i =0;
    while (s[i] != '\0') {
        i++;
    }
    s[i]=c;
    s[i+1]='\0';
}

void strreverter(string in,string &out){
  int len = strlar(in);
  int m=0, n=len;
  char tem;
    while(n > m){
      tem = in[m];
      in[m++] = in[--n];
      in[n] = tem;
    }
    strcop(out,in);
}

Boolean strIsEnd(char c){

    return (c == '\0') ? TRUE : FALSE;

}

int strIndexOf(string s,char c){
    int i=0;
    while((strIsEnd(s[i])) && (s[i] != c))
        i++;
    return (strIsEnd(s[i]) == TRUE) ? 0 : i;

}

Boolean EsAlfabetico(string parametro)
{
    Boolean alfabetico=TRUE;
   int i=0;
   while (alfabetico && (parametro[i]!='.') && (parametro[i]!='\0'))
          {
             if (((parametro[i]>='0') && (parametro[i]<='9'))  || (((parametro[i]<'a' || parametro[i]>'z') && (parametro[i]<'A' || parametro[i]>'Z'))))
                   alfabetico=FALSE;
             else
                i++;
          }
   if ((parametro[0]=='\0') || (((parametro[0]<'a' || parametro[0]>'z') && (parametro[0]<'A' || parametro[0]>'Z'))))
        alfabetico=FALSE;
   return alfabetico;
}

void strtrimlast(string s1, string &s2)
{
  int i = 0;
  int j = 0;
  //se agrega
  string aux = new char[MAX];
  while ((s1[i] != ' ') && (s1[i]!='\0'))  // Busco el primer espacio
  {
    aux[j]=s1[i];
    j++;
    i++;
  }

  while((s1[i] == ' ') &&  (s1[i]!='\0')) // Descarto todos los espacios
   {
    i++;
  }
  while(s1[i] != '\0'){   // Cargo los restntes caracteres
    aux[j] = s1[i];
    j++;
    i++;
  }
  aux[j] = '\0';
  strcop(s2,aux);
  strdestruir(aux);

}

void charToString(string &s,char c){
    //s = new char[2];
    s[0]= c;
    s[1]='\0';
}

void SobreEscritura(string parametro,char &prim,char &ult)
{
    string aux1,aux2;
    strcrear(aux1);
    strcrear(aux2);
    strtrim(parametro,aux1);
    strtrimlast(aux1,aux2);
    prim=aux2[0];
    ult=aux2[1];
    strdestruir(aux1);
    strdestruir(aux2);
}


void BajarString (string s, FILE * f)
{
    int i=0;
    while(s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

void LevantarString (string &s, FILE * f)
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
