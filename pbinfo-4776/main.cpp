//Iuscinschi Simona
#include <fstream>
#define NMAX 205
using namespace std;
ifstream fin("plasmopara.in");
ofstream fout("plasmopara.out");
int n,m,z,cer;
int b[NMAX][NMAX];
int fr[NMAX];
char a[NMAX][NMAX];
int dl[]= {-1,0,1,0};
int dc[]= {0,1,0,-1};
struct poz
{
    int l,c;
};
void citire()
{
    int i,j;
    fin>>cer;
    fin>>n>>m>>z;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];
}
void bordare()
{
    int i,j;
    ///bordare
    for(i=0; i<=n+1; i++) b[i][0]=b[i][m+1]=-1;
    for(j=0; j<=m+1; j++) b[0][j]=b[n+1][j]=-1;
}
void rezolvare()
{
    poz C[NMAX*NMAX],x,v;
    int p,u,k;
    p=0;
    u=-1;
    ///se introduc in coada colturile cu soi hibrid
    if(a[1][1]!='N')
    {
        u++;
        C[u].l=1;
        C[u].c=1;
        b[1][1]=1;
        fr[1]++;
        a[1][1]='*';
    }
    if(a[1][m]!='N')
    {
        u++;
        C[u].l=1;
        C[u].c=m;
        b[1][m]=1;
        fr[1]++;
        a[1][m]='*';
    }
    if(a[n][1]!='N')
    {
        u++;
        C[u].l=n;
        C[u].c=1;
        b[n][1]=1;
        fr[1]++;
        a[n][1]='*';
    }
    if(a[n][m]!='N')
    {
        u++;
        C[u].l=n;
        C[u].c=m;
        b[n][m]=1;
        fr[1]++;
        a[n][m]='*';
    }
    ///prelucrarea cozii
    while (p<=u)
    {
        x=C[p++];
        if(b[x.l][x.c]<z)
            for (k=0; k<4; k++)
            {
                v.l=x.l+dl[k];
                v.c=x.c+dc[k];
                if (a[v.l][v.c]!='N' && b[v.l][v.c]==0)
                {
                    u++;
                    C[u]=v;
                    b[v.l][v.c]=b[x.l][x.c]+1;
                    fr[b[v.l][v.c]]++;
                    a[v.l][v.c]='*';
                }
            }
    }
}
void cer1()
{
    int i,j,cnt=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]=='-')
                cnt++;
    fout<<cnt<<endl;
}
void cer2()
{
    int mx=0,poz=0;
    for(int i=1;i<=z;i++)
        if(fr[i]>mx) mx=fr[i],poz=i;
    fout<<poz<<endl;
}
int main()
{
    citire();
    bordare();
    rezolvare();
    if(cer==1)
        cer1();
    else
        cer2();
    return 0;
}