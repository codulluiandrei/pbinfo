// Todoran Alexandru Raul, clasa a V-a, Colegiul National Aurel Vlaicu Orastie
#include <iostream>
#include <fstream>
using namespace std;
int n,a,x[1000002],r[1000002],m,i,o,s,mx;
int main()
{
    ifstream fin ("mdiv.in");
    ofstream fout ("mdiv.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        if(a>mx)mx=a;
        x[a]++;
    }
    fin>>m;
    for(i=1;i<=m;i++)
    {
        fin>>a;
        if(r[a]==0)
        {
            if(a!=1)
                for(o=0;o<=mx;o+=a)r[a]+=x[o];
            else r[a]=n;
        }
        fout<<r[a]<<"\n";
    }
    return 0;
}