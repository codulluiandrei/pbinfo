#include <fstream>
#include <cstring>
#define NMAX 1505
using namespace std;
ifstream f("v.in");
ofstream g("v.out");
long long l1[NMAX], l2[NMAX], r1[NMAX], r2[NMAX];
int main()
{
    int n,m;
    f>>n>>m;
    int maxi=-2000000009, cmax, lmax;
    for (int j = 1; j <= m; ++j)
    {
        f >> l1[j];
        r1[j] = l1[j];
    }
    for(int i=2; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            int x;
            f>>x;
            l2[j] = l1[j - 1] + x;
            r2[j] = r1[j + 1] + x;
            if ( (j>=i) &&  (j<=m-i+1) && (l2[j] + r2[j] - x > maxi))
            {
                maxi = l2[j] + r2[j] - x;
                cmax = j - i + 1;
                lmax = i;
            }
            l1[j-1]=l2[j-1];
            r1[j-1]=r2[j-1];
        }
        l1[m]=l2[m];
        r1[m]=r2[m];
        /*memcpy(l1, l2, sizeof(l1));
        memcpy(r1, r2, sizeof(r1));*/
    }
    g<<maxi << ' ' << cmax << ' ' << lmax << '\n';
    return 0;
}