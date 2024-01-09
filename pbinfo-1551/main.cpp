#include <fstream>
using namespace std;
ifstream f("dslm.in");
ofstream g("dslm.out");

int a[21][21],n,p, d[100], dmax[100],lgmax;

void citire()
{
    int i,x,y;
    f>>n>>p;
    while(f>>x>>y)
        a[x][y]=1;
}
void copie(int lg)
{
    lgmax=lg;
    for(int i=1; i<=lg; i++) dmax[i]=d[i];
}

void scrie_drum()
{
    for(int i=1; i<=lgmax; i++)
        g<<dmax[i]<<" ";
    g<<endl;
}

void dfs(int x, int lg)
{
    d[lg]=x;
    int ex_s=0, y;
    for(y=1; y<=n; y++)
        if(a[x][y])
        {
            a[x][y]=0;
            ex_s=1;
            dfs(y,lg+1);
            a[x][y]=1;
        }
    if(ex_s==0 && lg>lgmax)
        copie(lg);
}

int main()
{
    citire();
    dfs(p,1);
    scrie_drum();
    return 0;
}
