#include <fstream>
#include <iostream>
#include<string.h>
using namespace std;
ifstream fin("expresie9.in");
ofstream fout("expresie9.out");
int s1[2000],s2[2000],n,t,a[1000],vmax[2000];
char c[1001],*p;
void scrie(int a[])
{
    for(int i=a[0];i>=1;i--)fout<<a[i];
    fout<<endl;
}
void scrie1(int a[])
{
    int i;
    for(int i=a[0];i>=1;i--)cout<<a[i];
    cout<<endl;
}
void suma(int s[],int a[])//s=s+a
{
    int i,t,nr;
    nr=s[0];
    if(a[0]>nr)nr=a[0];
    for(i=1;i<=a[0];i++)s[i]=s[i]+a[i];
    t=0;
    for(i=1;i<=nr;i++)
    {
        s[i]=s[i]+t;
        t=s[i]/10;
        s[i]=s[i]%10;
    }
    if(t>0)
    {
        nr++;
        s[nr]=1;
    }
    s[0]=nr;
}
void zero( int y[])
{
    for(int i=0;i<1000;i++)y[i]=0;
}
void transf(char *p)
{
    int i,lg,cod,u,v;
    char aux;
    lg=0;
    for(i=0;i<strlen(p);i++)
        {
           cod=p[i]-'a'+1;
           if(cod<=9)
           {
               lg++;
               a[lg]=cod;
           }
           else
            {
               lg++;
               a[lg]=cod/10;
               lg++;
               a[lg]=cod%10;
            }
        }
    a[0]=lg;
    u=1;v=lg;
    while(u<v)
    {
        aux=a[u]; a[u]=a[v];a[v]=aux;
        u++; v--;
    }
}
int compara(int x[],int y[]) /// returnez 1, -1 sau 0
{
    if(x[0]>y[0]) return 1;
    if(x[0]<y[0])
        return -1;
    for(int i=x[0];i>=1;i--)
        {
            if(x[i]>y[i])return 1;
            if(x[i]<y[i])return -1;
        }
    return 0;
}
void copie(int vmax[],int a[])
{
    for(int i=0;i<=a[0];i++) vmax[i]=a[i];
}
void cerinta2()
{
   int i,rez;
   char sep[]="+<=>";
   vmax[0]=1;
   for(i=1;i<=n;i++)
  {
   fin.getline(c,1001);
   p=strtok(c,sep);
   while(p!=NULL)
   {
       zero(a);///a=0
       transf(p);/// compun a
       rez=compara(a,vmax);/// a>vmax
       if(rez==1)copie(vmax,a);/// vmax=a
       p=strtok(NULL,sep);
   }
  }
   scrie(vmax);
}
void evaluare(char *d,int z[])
{
    zero(z);
    z[0]=1;
    p=strtok(d,"+");
   while(p!=NULL)
   {
       zero(a);///a=0
       transf(p);/// compun a
       //scrie1(a);
       suma(z,a);
       p=strtok(NULL,"+");
   }
}
void cerinta1()
{
 char *q,*r,aux[3];
 int i,lg,j,rez,k;
 for(k=1;k<=n;k++)
 {
     fin.getline(c,1000);
     lg=strlen(c);
     i=0;
     while(c[i]!='<' &&c[i]!='>' && i<lg)
        i++;
     if(i==lg)
     {
         evaluare(c,s1);
         scrie(s1);
         zero(s1);
         zero(a);
     }
     else
     {
         j=i;
         strncpy(aux,c+i,2);
         if(aux[1]=='=')aux[2]='\0';
         else aux[1]='\0';
         while(c[j]=='>' || c[j]=='<' || c[j]=='=')j++;
         c[i]='\0';
         evaluare(c,s1);
         evaluare(c+j,s2);
         rez=compara(s1,s2);
         if(strlen(aux)==1)
            if(aux[0]=='>')fout<< (rez==1)<<endl;
            else fout<< (rez==-1)<<endl;
        else
            if(aux[0]=='>')fout<< (rez>=0)<<endl;
            else fout<< (rez<=0)<<endl;
            zero(s1);
            zero(s2);
     }
 }
}
int main()
{
    fin>>t>>n;
    fin.get();
    if(t==2)cerinta1();
    else cerinta2();
    return 0;
}