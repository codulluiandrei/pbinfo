#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream fin("codul.in");
ofstream fout("codul.out");
int dp[205][205], n, m;
char a[205], b[205];
void LCS()
{
    int i, j;
    for(i = n - 1; i >= 0; i--)
        for(j = m - 1; j >= 0; j--)
        {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
}
void Search(int i1, int j1, int k)
{
    int i, j, p1 = 0, p2 = 0;
    char mx = '0';
    if(k >= 1)
    {
        for(i = i1; i < n; i++)
        {
            for(j = j1; j < m; j++)
                if(dp[i][j] == k && a[i] == b[j] && a[i] > mx)
                {
                    mx = a[i];
                    p1 = i;
                    p2 = j;
                }
        }
        fout << mx;
        Search(p1 + 1, p2 + 1, k - 1);
    }
}
int main()
{
    fin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    LCS();
    Search(0,0,dp[0][0]);
    fout << "\n";
    fout.close();
    return 0;
}