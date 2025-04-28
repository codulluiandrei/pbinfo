/// stud. Theodor-Pierre Moroianu
/// Universitatea din Bucuresti
#include <bits/stdc++.h>
using namespace std;
const int VMAX = 1000000;
const int NMAX = 1000;
int solve(vector <int> v)
{
    vector <vector <int>> dp(v.size());
    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        dp[i] = vector <int> (i + 2, 0);
        for (int j = 0; j <= i; j++) {
            dp[i][j] = v[i] + (i ? max(0, dp[i - 1][j]) : 0);
            ans = max(ans, dp[i][j]);
            for (int b = 1; b <= i; b *= 2)
                if (j & b)
                    dp[i][j] = max(dp[i][j], dp[i - b][j - b]);    
        }
    } 
    return ans;
}
int main()
{
    ifstream in("recyclebin.in");
    ofstream out("recyclebin.out");
    int n;
    in >> n;
    assert(n <= NMAX);
    vector <int> v(n);
    for (auto & i : v) {
        in >> i;
        assert(abs(i) <= VMAX);
    }
    out << solve(v) << '\n';
    return 0;
}