#include <fstream>
using namespace std;
ifstream f("tabla.in");
ofstream g("tabla.out");
int a[22][22],n,vmax,pt;
void sch(int i1,int j1,int i2,int j2)
{
    int aux;
    aux=a[i1][j1];
    a[i1][j1]=a[i2][j2];
    a[i2][j2]=aux;
}
int orizontal(int i,int j)
{    int p=0,k;
    //dreapta
    k=j+1;
    while(a[i][k]==a[i][j])
    {
        p++;k++;
    }
    //stanga
    k=j-1;
    while(a[i][k]==a[i][j])
    {
        p++;k--;
    }
    return p;
}
int vertical(int i,int j)
{    int p=0,k;
    //jos
    k=i+1;
    while(a[k][j]==a[i][j])
    {
        p++;k++;
    }
    //sus
    k=i-1;
    while(a[k][j]==a[i][j])
    {
        p++;k--;
    }
    return p;
}
void rezolvao(int i,int j)  //vecini orizontal
{int nr[5]={0},t;
    sch(i,j,i,j+1);
    pt=0;
    nr[1]=orizontal(i,j);
    nr[2]=vertical(i,j);
    nr[3]=orizontal(i,j+1);
    nr[4]=vertical(i,j+1);
    for(t=1;t<=4;t++)
        if(nr[t]>=2)pt=pt+1+nr[t]-2;
    if(nr[1]>=2 &&nr[2]>=2)pt=pt+3;
    if(nr[3]>=2&&nr[4]>=2)pt=pt+3;
    if(pt>vmax)vmax=pt;
    sch(i,j,i,j+1);
    }
void rezolvav(int i,int j)  //vecini vertical
{int nr[5]={0},t;
    sch(i,j,i+1,j);
    pt=0;
    nr[1]=orizontal(i,j);
    nr[2]=vertical(i,j);
    nr[3]=orizontal(i+1,j);
    nr[4]=vertical(i+1,j);
    for(t=1;t<=4;t++)
        if(nr[t]>=2)pt=pt+1+nr[t]-2;
    if(nr[1]>=2&&nr[2]>=2)pt=pt+3;
    if(nr[3]>=2&&nr[4]>=2)pt=pt+3;
    if(pt>vmax)vmax=pt;
    sch(i,j,i+1,j);
}
int main()
{    int i,j;
    //citire
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    //bordare
    for(i=0;i<=n+1;i++)
        a[i][0]=a[0][i]=a[n+1][i]=a[i][n+1]=6;
    vmax=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            //vecini pe linie
            if(a[i][j+1]<6 &&a[i][j]!=a[i][j+1])
                rezolvao(i,j);
            //vecini pe coloana
            if(a[i+1][j]<6 && a[i][j]!=a[i+1][j])
                rezolvav(i,j);
        }
    g<<vmax<<endl;
    return 0;
}