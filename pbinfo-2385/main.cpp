#include <fstream>
#include <iostream>
using namespace std;
ifstream f("oaste.in");
ofstream g("oaste.out");

int a[105][105],n,m,s,smax=0,I,J,Imax,Jmax,nrmax,nr,pozi,pozj,pozimax,pozjmax;

void citeste()
{
    f>>n>>m;
    int i,j,x;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            f>>x;
            a[i][j]=x;
        }
}
void bordare()
{
    for(int j=0; j<=m+1; j++) a[0][j]=a[n+1][j]=0;
    for(int i=0; i<=n+1; i++) a[i][0]=a[i][m+1]=0;
}

void fill(int i, int j)
{
    if(nr<a[i][j])
    {
        nr=a[i][j];
        pozi=i;
        pozj=j;
    }
    else
        if(nr == a[i][j])
        {
            if(pozi > i)
                pozi = i, pozj = j;
            else
                if(pozi == i && pozj > j)
                    pozj = j;
        }
        
    s=s+a[i][j];
    a[i][j]=a[i][j]*(-1);
    if(a[i-1][j]>0)fill(i-1,j);
    if(a[i][j+1]>0)fill(i,j+1);
    if(a[i+1][j]>0)fill(i+1,j);
    if(a[i][j-1]>0)fill(i,j-1);
}
int main()
{
    citeste();
    bordare();
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]>0)
            {
                s=0;
                nr=0;
                pozi=i;
                pozj=j;
                I=i;
                J=j;
                fill(i,j);
                if(smax<s)
                {
                    smax=s;
                    Imax=I;
                    Jmax=J;
                    nrmax=nr;
                    pozimax=pozi;
                    pozjmax=pozj;
                }
            }
    g<<nrmax<<" "<<pozimax<<" "<<pozjmax;

    return 0;
}
