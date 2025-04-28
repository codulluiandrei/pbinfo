#include <fstream>
#define N 1002
using namespace std;
ifstream f("pct.in");
ofstream g("pct.out");
int n, i, j, k, nr, maxim, x, y;
int a[N][N], b[N][N], c[N];
int main()
{
    f >> n >> k;
    for(i = 1; i <= n; i++)
    {
        f >> x >> y;
        a[x+1][y+1] = 1;
    }
    for(i = 1; i <= 1001; i++)
        for(j = 1; j <= 1001; j++)
    {
        c[j] += a[i][j];
        b[i][j] = b[i][j-1] + c[j];
    }
    maxim = 0;
    for(i = 1; i <= 1001-k; i++)
        for(j = 1; j <= 1001-k; j++)
    {
        nr = b[i+k][j+k]-b[i+k][j-1]-b[i-1][j+k]+b[i-1][j-1];
        if(nr > maxim) maxim = nr;
    }
    g << maxim;
    return 0;
}