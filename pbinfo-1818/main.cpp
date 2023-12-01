#include <fstream>

using namespace std;
ifstream f("brain.in");
ofstream g("brain.out");

int n,i,j,x,v[1000000];
long long nmax,nmin;

int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>x;
        if(x==i)
			v[++j]=x;

    }
    for(i=1;i<=j;++i)
    {
        g<<v[i]<<" ";
        nmax+=v[i];
    }
    g<<'\n';
    g<<nmax<<'\n';
    if(v[1]!=1)
		g<<1;
    else
    {
        nmin=1;
        i=1;
        while(i<=j && v[i]<=nmin)
			nmin+=v[i++];
        g<<nmin<<endl;
    }
    g.close();
    f.close();
    return 0;
}
