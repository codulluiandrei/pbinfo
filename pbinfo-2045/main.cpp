/// Flavius Boian
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("faleza.in");
ofstream g("faleza.out");
int a[200001],b[200001],i,n,poza,pozb,k;
int main()
{
    f>>n;
    for(i=1; i<=n; i++) ///citesc caracter cu caracter si le pun in vector
    {
        f>>a[i];
    }
    for(i=1; i<=n; i++)
    {
        f>>b[i];
    }
    i=1;
    while(a[i]==0 && b[i]==0) ///caut primul 1
    {
        k++;
        a[i]=b[i]==k;
        i++;
        if(i==n+1)
            break;
    }
    if(a[i]==1)
        poza=1; ///marchez randul pe care ma deplasez, cel in care am gasit primul 1
    else if(b[i]==1)
        pozb=1;
    while(i<n)
    {
        while(a[i]==0 && b[i]==0) /// daca ajung in cazul in care pe pozitia curenta am 0 pe amandoua liniile
        {                         /// merg pana ajung la primul 1 si cresc numarul de placute
        k++;
        a[i]=b[i]==k;
        i++;
        if(i==n+1)
            break;
        }
    if(a[i]==1)
        {
            poza=1; ///marchez randul pe care ma deplasez,cel in care am gasit primul 1 dupa secventa de 0
            pozb=0;
        }
    else if(b[i]==1)
        {
            pozb=1;
            poza=0;
        }
        if(poza==1)
        {
            while(a[i+1]==1 and i!=n+1) ///ma deplasez pe linia curenta pana la capatul secventei de 1
                i++;
            if(i==n) break;
            else
            if(a[i+1]==0 and b[i]==0) /// daca urmatorul element e 0 si nu pot sa ma duc nici jos
            {
                i++;
                k++; ///creste nr de patratele necesare
                a[i]=b[i-1]=k;
            }
            else if(a[i+1]==0 and b[i]!=0) /// daca urmatorul element e 0, dar am 1 pe linia cealalta
            {
                i++;
                poza=0;
                pozb=1; /// schimb randul
            }
            else if(a[i+1]==0 and b[i]!=0 and b[i+1]!=0) ///ma duc jos si la dreapta pe randul 2, daca acolo am elemente nenule
            {
                i++;
                poza=0;
                pozb=1;
            }
            if(i==n && a[i]==0 && b[i]==0) /// daca am ajuns pe ultima pozitie si am 0 pe amandoua liniile
                k++; /// creste numarul de placute
        }
        else if(pozb==1) /// daca sunt pe randul 2
        {
            while(b[i+1]==1 and i!=n+1) /// fac aceleasi verificari ca la randul 1
                i++;
            if(i==n) break;
            if(b[i+1]==0 and a[i]==0)
            {
                i++;
                k++;
                b[i]=a[i-1]=k;
            }
            else if(b[i+1]==0 and a[i]!=0)
            {
                i++;
                poza=1;
                pozb=0;
            }
            else if(b[i+1]==0 and a[i]!=0 and a[i+1]!=0)
            {
                i++;
                poza=1;
                pozb=0;
            }
            if(i==n && a[i]==0 && b[i]==0)
                k++;
        }
    }
    g<<k;
    return 0;
}