/*
    Prof. Daniel Popa, Colegiul National Aurel Vlaicu Orastie
    Divide et Impera
*/
#include <iostream>
#include <fstream>
#define si short int
#define ar(l1, c1, l2, c2) (l2-l1+1)*(c2-c1+1)
using namespace std;
typedef struct pom{si l,c;};
pom a[1002];
si n,m,k=1,i;
int smax=0;
si cauta(si l1, si c1, si l2, si c2, si k)
{
    while(k<=m)
        if(a[k].l>=l1 and a[k].l<=l2 and a[k].c>=c1 and a[k].c<=c2) return k;
            else k++;
    return 0;
}
void arie(si l1, si c1, si l2, si c2)
{
    int s=(l2-l1+1)*(c2-c1+1);
     smax=max(s,smax);
}
int z;
void div(si l1, si c1, si l2, si c2, si p)
{
    int sa=ar(l1,c1,l2,c2);
   if(smax<sa)
   {
        p=cauta( l1, c1, l2, c2, p);
       if(p==0)smax=max(smax, sa);
         else
         {
             div(l1, c1, l2, a[p].c-1,p+1);
             div(l1, a[p].c+1, l2, c2,p+1);
             div(l1, c1, a[p].l-1, c2,p+1);
             div(a[p].l+1, c1, l2, c2,p+1);
         }
   }
}
int main()
{
    ifstream fin("hambar.in");
    ofstream fout("hambar.out");
    fin>>n>>m;
    for(i=1;i<=m;i++)fin>>a[i].l>>a[i].c;
    div(1,1,n,n,1);
    fout<<smax;
    return 0;
}