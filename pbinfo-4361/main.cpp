#include <bits/stdc++.h>
using namespace std;
long long n, h, d, l, r, down[200005], ans, k;
struct segment{
    long long st, dr;
    bool operator<(const segment &a) const {
        if (st != a.st)
            return st < a.st;
        return dr < a.dr;
    }
}v[200005], a[200005];
int main()
{   
    cin>>n>>h;
    for(int i = 1; i <= n; i++)
        cin>>a[i].st>>a[i].dr;
    sort(a + 1, a + n + 1);
    k = 0;
    l = a[1].st;
    r = a[1].dr;
    for (int i = 1; i <= n; i++) {
        if (a[i].st <= r) {
            r = max(r, a[i].dr);
        } else {
            v[++k] = {l, r};
            l = a[i].st;
            r = a[i].dr;
        }
    }
    v[++k] = {l, r};
    down[1] = 0;
    for (int i = 2; i <= k; i++)
    {
        down[i] = down[i - 1] + v[i].st - v[i - 1].dr;
    }
    ans = INT_MIN;
    long long val = -1;
    l = 1, r = 1;
    while (l <= k)
    {
        while (r <= k && (down[r] - down[l]) < h)
        {
            r++;
        }
        val = h - (down[r - 1] - down[l]);
        ans = max(ans, v[r - 1].dr - v[l].st + val);
        l++;
    }
    cout << ans;
} 