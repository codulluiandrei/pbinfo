#include <fstream>
using namespace std;
#define N 1010
ifstream f("forta.in");
ofstream g("forta.out");
long long a[N], b[N];
int forta[19*N], n, poz[19*N], nn;
int main()
{
    f>>n;
    int i;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=n; i++)
    {
        int fri[10] = {}, j;
        long long x=a[i];
        do
        {
            fri[x%10]++;
            x/=10;
        }
        while(x);
        for(j=1; j<=n; j++)
            if(i!=j)
            {
                int frj[10] = {};
                x=a[j];
                do
                {
                    frj[x%10]++;
                    x/=10;
                }
                while(x);
                for(int k=0; k<=9; k++)
                    forta[i]+=min(fri[k], frj[k]);
            }
        poz[forta[i]]++;
        nn=max(nn, forta[i]);
    }
    for(i=1; i<=nn; i++) poz[i]+=poz[i-1];
    for(i=1; i<=n; i++) b[poz[forta[i]]]=a[i], poz[forta[i]]--;
    for(i=1; i<=n; i++) g<<b[i]<<' ';
    return 0;
}