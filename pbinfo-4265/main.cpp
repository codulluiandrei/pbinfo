#include <bits/stdc++.h>
using namespace std;
int n, a[160005];
/// cea mai din dreapta pozitie p cu val + a[p] <= X
int CautBin(int j, int val, int X)
{
    if (val + a[n] <= X) return n;
    if (val + a[j] > X) return -1;
    int st, dr, mij, p;
    st = j; dr = n;
    p = -1;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (val + a[mij] <= X)
        {
            p = mij;
            st = mij + 1;
        }
        else dr = mij - 1;
    }
    return p;
}
int main()
{
    int i, j, A, B;
    long long cnt = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cin >> A >> B;
    sort(a + 1, a + n + 1);
    /// cate perechi au suma a[i]+a[j] <= B
    for (i = 1; i < n; i++)
    {
        j = CautBin(i + 1, a[i], B);
        if (j != -1) cnt += (j - i);
    }
    /// cate perechi au suma a[i]+a[j] <= A - 1
    for (i = 1; i < n; i++)
    {
        j = CautBin(i + 1, a[i], A - 1);
        if (j != -1) cnt -= (j - i);
    }
    cout << cnt << "\n";
    return 0;
}