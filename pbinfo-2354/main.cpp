#include <fstream>
#include <cstring>
#include<algorithm>
#include<vector>
#define MAXN 101
using namespace std;
ifstream fin("autostrada.in");
ofstream fout("autostrada.out");
struct lista
{
    int nod;
    int c;
    lista *urm;
};
lista *g[MAXN];
struct Punct
{
    int x, y ;
    friend bool operator <(Punct p1, Punct p2)
    {
        if (p1.x != p2.x) return p1.x < p2.x ;
        else return p1.y < p2.y ;
    }
};
vector <Punct> v ;
int t[101],niv[101],l[101],viz[101],n,m;
void ad(int x,int y)
{
    lista *p;
    p=new lista;
    p->nod=y;
    p->c=0;
    p->urm=g[x];
    g[x]=p;
}
void citgraf()
{
    int x,y,k;
    fin>>n>>m;
    for(k=1; k<=m; k++)
    {
        fin>>x>>y;
        ad(x,y);
        ad(y,x);
    }
}
void df(int nod)
{
    lista *p;
    int x;
    viz[nod]=1;
    l[nod]=niv[nod];
    for(p=g[nod]; p; p=p->urm)
    {
        x=p->nod;
        if(!viz[x])
        {
            niv[x]=niv[nod]+1;
            t[x]=nod;
            df(x);
            if(l[nod]>l[x])
                l[nod]=l[x];
            if(l[x]>niv[nod])
                p->c=1;
        }
        else if(x!=t[nod]&&l[nod]>niv[x])
            l[nod]=niv[x];
    }
}
int main()
{
    int i,k=0;
    lista *p;
    Punct q ;
    citgraf();
    for(i=1; i<=n; i++)
        if(!viz[i])
        {
            niv[i]=1;
            df(i);
        }
    for(i=1; i<=n; i++)
        for(p=g[i]; p; p=p->urm)
            if(p->c==1)
                k++;
    fout<<k<<'\n';
    for(i=1; i<=n; i++)
        for(p=g[i]; p; p=p->urm)
            if(p->c==1)
            {
                if(i>p->nod) swap(i,p->nod);
                q.x=i;
                q.y=p->nod;
                v.push_back(q) ;
            }
    sort( v.begin() , v.end() , less<Punct>() ) ;
    for (i=0 ; i<k ; i++)
        fout<<v[i].x<<" "<<v[i].y<<"\n" ;
    return 0;
}