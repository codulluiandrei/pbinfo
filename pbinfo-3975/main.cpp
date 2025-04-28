#include <bits/stdc++.h>
using namespace std;
ifstream fin("intervale.in");
ofstream fout("intervale.out");
struct atom
{
    int x, t;
    bool operator < (const atom alt) const
    {
        if(x == alt.x)
            return t < alt.t;
        return x < alt.x;
    }
};
int k, n, a,b;
atom v[200005];
int main()
{
    int i, cnt, ans;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> a >> b;
        v[++k] = {a, 0};
        v[++k] = {b, 1};
    }
    sort(v + 1, v + k + 1);
    cnt = ans = 0;
    for(i = 1; i <= k; i++)
    {
        if(v[i].t == 0) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    fout << ans << "\n";
    fout.close();
    return 0;
}