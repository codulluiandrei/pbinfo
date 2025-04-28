/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
vector<int> v, st, d;
vector<vector<int>> vd;
int n, res(1e9), curr;
inline void Back(int k)
{
    if (k == 0 && res > curr)
        res = curr;
    if (curr >= res)
        return;
    for (const int& x : vd[st[k+1]])
    {
        st[k] = x;
        curr += abs(st[k] - v[k]);
        if (curr < res)
        	Back(k - 1);
        curr -= abs(st[k] - v[k]);
    }
}
int main()
{
    cin >> n;
    v = st = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = v[n]; i; --i)
        if (v[n] % i == 0)
            d.emplace_back(i);
    vd = vector<vector<int>>(v[n] + 1);
    for (size_t i = 0; i < d.size(); ++i)
        for (size_t j = i; j < d.size(); ++j)
            if (d[i] % d[j] == 0)
                vd[d[i]].emplace_back(d[j]);
    st[n] = v[n];
    Back(n - 1);
    cout << res;
    return 0;
}