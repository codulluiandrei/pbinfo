#include <fstream>
using namespace std;
int x[10001],n,k,v[10001];

ifstream f("minge.in");
ofstream g("minge.out");

int main()
{
    int i, nr=0,a,b,ok,cer;
    f>>cer>>n>>k;
    for(i=1; i<=k; i++)
    {
        f>>a>>b;
        x[a]=b;
        v[a]=v[b]=1;
    }
    for(i=1; i<=n; i++)nr+=v[i];

    if(cer==1)
    {
        g<<n-nr<<endl;
        return 0;
    }
    for(a=1; a<=n; a++)
        if(x[a])
        {
            ok=1;
            for(i=1; i<=n; i++)
                if(x[i]==a)ok=0;

            if(ok) break;
        }

    if(ok==0)g<<0<<endl;
    else
        do
        {
            g<<a<<" ";
            a=x[a];
        }
        while(a!=0);
    g<<endl;
    return 0;
}
