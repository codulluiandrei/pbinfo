#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("furnica.in");
ofstream g ("furnica.out");
int n,i,j,b[250],c[200][200],nn,x=1,y=1,a[200][200],s,maxx,r;
int main()
{
    f>>n;
    f>>nn;
    for(i=1;i<=nn;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=(i+j)%6;

        }
    }
    s=s+a[x][y];
    a[x][y]=0;
    c[x][y]++;
    for(i=1;i<=nn;i++)
    {
        if(b[i]==1){x--;}
        if(b[i]==2){x--;y++;}
        if(b[i]==3){y++;}
        if(b[i]==4){x++;y++;}
        if(b[i]==5){x++;}
        if(b[i]==6){x++;y--;}
        if(b[i]==7){y--;}
        if(b[i]==8){x--;y--;}
        s=s+a[x][y];
        a[x][y]=0;
        c[x][y]++;
    }
    g<<s;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(maxx<c[i][j])maxx=c[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(maxx==c[i][j])r++;
        }
    }
    g<<" "<<r;
    return 0;
}
