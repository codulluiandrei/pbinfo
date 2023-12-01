//autor: prof. Liviu-Vasile Pinzaru, Palatul Copiilor Suceava & Clubul Copiilor Falticeni
#include <fstream>
using namespace std;
const int dim=500008;
short int v[dim];

int w[10];
int W[10];

int main()
{
    ifstream f("maxim.in");
    ofstream g("maxim.out");
    int N,i,j,poz=0,M,x,z,k=0,ii;
    int ok=1;
    int p;

f>>p;
f>>N>>M;

for(i=1;i<=N;++i)
    f>>v[i];


for(i=1;i<=M;++i)
{
    x=v[i];
    w[x]++;
}


if(p==1)
{
    if(w[0]==M)
        g<<0;

    else
    {
        for(j=9;j>=0;j--)
          for(i=1;i<=w[j];i++)
            g<<j;
    }
}


if(p==2)
{

for(j=0;j<10;j++)
    W[j]=w[j];

for(i=M+1;i<=N;++i)
{
    x=v[i];
    w[x]++;
    z=v[i-M];
    w[z]--;

    ok=1;
    //comparam sirurile
    for(j=9;j>0;j--)
    {
        if(W[j]!=w[j])
        {
            if(w[j]>W[j])
            {
                ok=2;
                for(ii=0;ii<=9;++ii)
                    W[ii]=w[ii];
                poz=i-M+1;
                //g<<"gasit la "<<i<<'\n';

            }
            else //(w[j]<W[j])
            {
                ok=0;
            }

            break;
        }

    }

    if(ok==1)
    {
        poz=i-M+1;
    }
}

g<<poz;

}


    return 0;
}
