#include <fstream>

using namespace std;

ifstream fin("furnici.in");
ofstream fout("furnici.out");

int nr_divizori(int x)
{
    int d, e=0,p=1;
    for(d=2;d*d<=x;d++)
    {
        for(e=0;x%d==0;x=x/d)
            ++e;
        p=p*(e+1);
    }
    if(x!=1)
        p=p*2;
    return p;
}

int main()
{
    int n, x, k=0, d1, d2,l;

    fin>>n>>x;
    d1=nr_divizori(x);
    l=1;
    for(int i=2;i<=n;++i)
    {
        fin>>x;
        d2=nr_divizori(x);
        if(d1>d2)
            l++;
        else
            if(l>1){
                ++k;
                l=1;
        }
        d1=d2;
    }
    if(l>1)
        ++k;
    fout<<k;
    return 0;
}
