#include <fstream>
#define Nmax 1001
#define SQR 1001
#define MOD 1000000007
using namespace std;

ifstream f("cadouri2.in");
ofstream g("cadouri2.out");

int n,v[Nmax],p[SQR],nrp,fr[SQR],rez;

int main()
{
    //Ciur pana la sqrt(10^6)
    for (int i=2;i<SQR;i++)
        if (p[i]==0)
        {
            p[++nrp] = i;
            for (int j=i+i;j<SQR;j+=i)
                p[j] = 1;
        }

    f>>n;
    for (int i=1;i<=n;i++)
        f>>v[i];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=nrp && v[i]>1;j++)
        {
            while (v[i]%p[j]==0)
            {
                v[i]/=p[j];
                fr[j]++;
            }
        }
    }

    rez = 1;
    for (int i=1;i<=nrp;i++)
        rez = (1LL * rez * (fr[i]+1))%MOD;

    for (int i=1;i<=n;i++)
    {
        if (v[i]!=1)
        {
            int nr = 1;
            for (int j=i+1;j<=n;j++)
            {
                if (v[j]==v[i])
                {
                    nr++;
                    v[j] = 1;
                }
            }
            rez = (1LL * rez * (nr+1))%MOD;
        }
    }

    g<<rez;

    return 0;
}
