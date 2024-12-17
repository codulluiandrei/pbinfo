#include <fstream>
using namespace std;
ifstream cin("pitic.in");
ofstream cout("pitic.out");
long long dp[50][50];
int n, m;
int main()
{
    cin >> n >> m;
    dp[1][1] = 1;
    for(int j = 2; j <= m; ++j) {
        for(int i = 1; i <= j; ++i) {
            dp[i][j] = dp[i + 1][j - 1] + dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    cout << dp[1][m];
    return 0;
}
