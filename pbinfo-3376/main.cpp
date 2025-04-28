#include <fstream>
#include <iostream>
#include <cstring>
#define DIM 3001
#define LCUV 100
#define NCUV 300
using namespace std;
ifstream fin("asciimat.in");
ofstream fout("asciimat.out");
char s[DIM],*p;//fiecare caracter codificat ocupa 7 elemente
int m[NCUV+5][LCUV*7+5],cer,k,nr,i,j,t,x,poz,l,c,d1=1,d2=1;//d1,d2 dimensiunile matricei m
int main()
{
    fin>>cer;
    fin.get();
    fin.getline(s,DIM);
    fin>>k;
    //construire matrice
    p=strtok(s," ");
    while(p)
    {
        j=1;
        for(t=0; p[t]; t++)
        {
            x=p[t];
            poz=0;
            while(x)
            {
                m[d1][j+(7-poz)]=x%2;
                poz++;
                x=x/2;
            }
            j=j+7;//urmatorul caracter
        }
        if(j>d2)
            d2=j;//d2 primea j-7
        p=strtok(0," ");
        d1++;
    }
    d2++;//d2 il consider cu 1 mai mare decat numarul de coloane
    for(i=1; i<d1; i++)
        for(j=1; j<d2; j++)
            m[i][j]=m[i][j]+m[i-1][j]+m[i][j-1]-m[i-1][j-1];
    if(cer==1)//cerinta problemei 1
    {
        k=max(d1,d2);
        for(; k>2; k--)
            for(i=1; i<=d1-k; i++)
                for(j=1; j<=d2-k; j++)
                {
                    l=i+k-1;
                    c=j+k-1;
                    if(m[l][c]-m[i-1][c]-m[l][j-1]+m[i-1][j-1]==k*k)
                    {
                        fout<<k;
                        return 0;
                    }
                }
    }
    if(cer==2)//cerinta problemei 2
    {
        for(i=1; i<=d1-k; i++)
            for(j=1; j<=d2-k; j++)
            {
                l=i+k-1;
                c=j+k-1;
                if(m[l][c]-m[i-1][c]-m[l][j-1]+m[i-1][j-1]==k*k)
                    nr++;
            }
        fout<<nr;
    }
    return 0;
}