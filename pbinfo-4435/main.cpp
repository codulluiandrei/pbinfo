/*Flavius Boian 100*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("dominew.in");
ofstream g("dominew.out");
int n,m,i,j,x,st,dr,mij,poz,t,a[1000001],b[8001];
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
        f>>a[i];
    f>>m;
    for(i=1; i<=m; i++)
    {
        f>>b[i];
        st=1;
        dr=n;
        poz=0;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(a[mij]<b[i])
            {
                poz=mij;
                st=mij+1;
            }
            else
                dr=mij-1;
        }
        ///caut liniar pozitia pe care trebuie sa inserez in noul vector
        for(t=1; t<i; t++)
            if(b[i]>b[t])
                poz++;
        g<<poz+1<<" ";
    }
    return 0;
}