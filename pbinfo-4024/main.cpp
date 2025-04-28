#include <fstream>
using namespace std;
ifstream f("matprod.in");
ofstream g("matprod.out");
int n, i, j;
int a[1001][1001], s[1001][1001], suma[1001], sum[1001];
int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            f >> a[i][j];
    for(i = 1; i <= n; i++)
    {
        s[i][1] = s[i-1][1]+a[i][1]*suma[i-1];
        suma[i] = suma[i-1]+a[i][1];
    }
    for(i = 1; i <= n; i++)
    {
        sum[1] = suma[i];
        for(j = 2; j <= n; j++)
        {
            s[i][j] = s[i][j-1]+a[i][j]*sum[j-1];
            sum[j] = sum[j-1]+a[i][j];
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            g << s[i][j] << " ";
        g << "\n";
    }
    return 0;
}