#include <fstream>
#define N 100002
using namespace std;
ifstream f("ou.in");
ofstream g("ou.out");
long long n, i, nr, cant;
long long o[N], v[N];

int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> o[i];
        nr = min(min(i-1, n-i), o[i]/2);
        if(nr > 0)
        {
            cant = o[i] / (2 * nr);
            o[i] = o[i] % (2 * nr);
            v[i-nr] += cant;
            v[i+nr+1] -= cant;
            o[i] -= cant;
        }
    }
    for(i = 1; i <= n; i++)
    {
        v[i] += v[i-1];
        g << v[i] + o[i] << " ";
    }
    return 0;
}
