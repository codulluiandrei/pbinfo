#include <fstream>
#define NM 100000
using namespace std;
ifstream f("up.in");
ofstream g("up.out");
int n,L,st,dr,i,mijl;
int x[NM],a[NM];
int main()
{
    f>>n;
    L=0;
    for(i=1; i<=n; i++)
    {
        f>>x[i];
        st=1;
        dr=L;
        while(st<=dr)
        {
            mijl=(st+dr)/2;
            if(x[a[mijl]]<x[i])
                st=mijl+1;
            else
                dr=mijl-1;
        }
        a[st]=i;
        L=max(L,st);
    }
    g<<L<<'\n';
    return 0;
}