#include <bits/stdc++.h>
using namespace std;
int a[10003], n, K;
int F(int val)
{
    int cnt = 0, i, j, s;
    j = 1; s = 0;
    for (i = 1; i <= n; i++)
    {
        s += a[i];
        while (s > val)
        {
            s -= a[j];
            j++;
        }
        cnt += (i - j + 1);
    }
    return cnt;
}
int main()
{
    int i;
    long long nrSecv = 0;
    cin >> n >> K;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    /// cautare binara
    int st, dr, mij, val;
    st = 1; dr = 300000000; val = 1;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (F(mij) >= K)
        {
            val = mij;
            dr = mij - 1;
        }
        else st = mij + 1;
    }
    cout << val << "\n";
    return 0;
}