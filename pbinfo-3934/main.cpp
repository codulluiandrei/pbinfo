#include <fstream>
#define N 200003
using namespace std;
ifstream f("parale.in");
ofstream g("parale.out");
int n,m,i,j,x,dn;
int v[N];
long long sol;

int main()
{
    f >> n >> m;
    dn = 2*n;
    for(i = 1; i <= m; i++)
    {
        f >> x;
        if(v[x]==0)
        {
            j = x;
            while(j <= dn)
            {
                v[j] = 1;
                j = j+x;
            }
        }
    }
    sol = 1LL*n*n;
    for(i = 2; i <= n+1; i++)
        if(v[i]) sol -= i-1;
    for(i = n+2; i <= dn; i++)
        if(v[i]) sol -= dn-i+1;
    g << sol;
    return 0;
}