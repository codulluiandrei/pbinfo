#include <iostream>
#include <fstream>
using namespace std;
struct nod
{int inf;
 nod *leg;
} *L[20001];
ifstream f("nunta.in");
ofstream g("nunta.out");
int n,m,viz[20001],v[20001],k,nr,var,s;
void adaug(int x, int y)
{
    nod *c;
    c=new nod;
    c->inf=y;
    c->leg=L[x];
    L[x]=c;
}
void citire()
{
    int i,x,y;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        adaug(x,y);
        adaug(y,x);
    }
    f.close();
}
void DF(int i)
{
    nod *c;
    viz[i]=1;
    //cout<<i<<' ';
    nr++;
    for (c=L[i];c;c=c->leg)
        if (!viz[c->inf]) DF(c->inf);
}
int main()
{   int i,j;
    citire();
    for (i=1;i<=n;i++)
        if(!viz[i])
    {
        nr=0;
        DF(i);
        //cout<<'\n';
        if (nr>=2) v[++k]=nr;
    }
    g<<k<<'\n';
   /* for (i=1;i<=k ;i++) cout <<v[i]<<" ";
    cout<<endl;
    */
    s=0; //numarul de invitati din grupurile selectate
    var=0; // numarul de variante de aranjare a mesei cu cel putin n/2+1 invitati
    i=0; // indicele grupului curent
    while (s<=n/2 && i<=k) s+=v[++i];  // prima varianta posibila
    var+=k-i+1; // se aduna numarul de variante care incep cu v[1]
    j=1;
    while (i<=k)
     {
         s-=v[j];
         while (s<=n/2 && i<=k) s+=v[++i];
         var+=k-i+1; //se aduna numarul variantelor care incep cu V[j+1]
         j++;
     }
    g<<var;
    g.close();
    return 0;
}