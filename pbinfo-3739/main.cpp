#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("cafea.in");
ofstream out("cafea.out");

int K,s,nr;
struct vanzator
{
    int cant;
    int pret;
} v[100001];

bool comp(vanzator a,vanzator b)
{
    return 1.0*a.pret/a.cant<1.0*b.pret/b.cant;
}
int main()
{
    int i,sr;
    in>>K>>s>>nr;
    for(i=1; i<=nr; i++)
        in>>v[i].cant>>v[i].pret;
    sort(v+1,v+nr+1,comp);
    for(i=1; i<=nr && s>0 && K>0; i++)
    {
        if(v[i].cant<=K)
        {
            if(v[i].pret<=s)
            {
                K=K-v[i].cant;
                s=s-v[i].pret;

            }
            else s=0;
        }
        else
        {
            double valoare=1.0*v[i].pret/v[i].cant*K;
            if(valoare==(int)valoare) sr=valoare;
            else sr=valoare+1;
            if(s>=sr)
            {
                s=s-sr;
                K=0;
            }
            else s=0;
        }
    }
    out<<s;
    return 0;
}