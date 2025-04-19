#include <bits/stdc++.h>
#define oo 2000000001
using namespace std;
unordered_map<int, int> M;
int main()
{
    int i, n, x, ans;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        M[x]++;
    }
    ans = oo;
    for (auto w : M)
    {
        if (w.second == 1 && ans > w.first)
                ans = w.first;
    }
    cout << ans << "\n";
    return 0;
}