# include <bits/stdc++.h>
# define NM 1001
using namespace std;
ifstream f("fb_fmi.in");
ofstream g("fb_fmi.out");
int n, m, k;
int d[NM];
bool a[NM][NM];
int main()
{
    int x, y;
    f >> n >> m >> k;
    for(int i=1; i<=m; ++i){
        f >> x >> y;
        a[x][y] = a[y][x] = 1;
        /// nr. de prieteni = grad
        d[x]++;
        d[y]++;
    }
    int i = 1;
    while( i <= n ) {
        if (d[i] < k && d[i] > 0) {
            for (int j=1; j<=n; ++j)
                if (a[i][j]) {
                    a[i][j] = a[j][i] = 0;
                    --d[j];
                }
            d[i] = 0;
            i = 1;
        }
        else ++i;
    }
    int nr = 0;
    for(int i=1; i<=n; ++i)
        if (d[i]) ++nr;
    g << nr << '\n';
    if (nr == 0) return 0;
    for(int i=1; i<=n; ++i)
        if (d[i]) g << i << ' ';
    g << '\n';
    return 0;
}