#include <bits/stdc++.h>
#define MOD 1234567
using namespace std;
ifstream fin ("cub_dinamic.in");
ofstream fout ("cub_dinamic.out");
bool M[205][205][205];
int  dp[205][205][205];
int main()
{
    int n, m, i, j, k, x, y, z;
    fin >> n >> m;
    for (i=1; i<=m; i++){
        fin >> x >> y >> z;
        M[x][y][z] = 1;
    }
    dp[1][1][1] = 1;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            for (k=1; k<=n; k++){
                if ((i!=1 or j!=1 or k!=1) and M[i][j][k] == 0)
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1];
                dp[i][j][k] %= MOD;
            }
    fout << dp[n][n][n] << "\n";
    return 0;
}