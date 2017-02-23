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
  string aux;
  int i = 0;
  strcrear(aux);
  while((s1[i]!='\0') && (s1[i] != c)){
    i++;
  }
  if(s1[i] == c){
    int j = 0;
    while(s1[i]!= '\0'){
      s2[j]=s1[i];
      i++;
      j++;
    }
    s2[j] = '\0';
  }else{
    s2[0] = '\0';
  }

}

//Retorna un sub string desde index a un char dado.
void strfirst(string s1, int index, char c, string &s2){
  string aux;
  int i = index;

  while((s1[i]!='\0') && (s1[i] != c)){
    s2[i] = s1[i];
    i++;
  }

  s2[i] = '\0';
}

//Quita todos los espacios del principio
void strtrim(string s1, string &s2){
  int i = 0;
  int j = 0;

  while(s1[i] == ' '){
    i++;
  }

  while(s1[i] != '\0'){
    s2[j] = s1[i];
    j++;
    i++;
  }
  s2[j] = '\0';
}

