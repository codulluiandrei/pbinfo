//Todoran Alexandru Raul, clasa a V-a, Colegiul National Aurel Vlaicu Orastie.
#include <iostream>
#include <fstream>
using namespace std;
int n,a,x[1000002],i,s,mx,ok=1;
int main()
{
    ifstream fin ("mmult.in");
    ofstream fout ("mmult.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        x[a]++;
        if(a>mx)mx=a;
    }
    while(x[1])
    {
        i=1;
        while(x[i]){x[i]--;i++;}
        s++;
    }
    for(i=1;i<=mx;i++)if(x[i]){ok=0;break;}
    if(ok)fout<<s<<"\n";
    else fout<<"-1\n";
    return 0;
}