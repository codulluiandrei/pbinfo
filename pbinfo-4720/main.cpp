#include <iostream>
using namespace std;
int a[100001], fr[100001], n, k;
int main()
{
    int i, cnt, nrMax;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cnt = nrMax = 0;
    for (i = 0; i < n; i++)
    {
        fr[a[i]]++;
        if (fr[a[i]] == 1) cnt++;
    }
    if (k == 0)
    {
        cout << cnt << "\n";
        return 0;
    }
    if (k == n)
    {
        cout << "0\n";
        return 0;
    }
    for (i = 0; i < k; i++)
    {
        fr[a[i]]--;
        if (fr[a[i]] == 0) cnt--;
    }
    nrMax = cnt;
    for (i = k; i < n; i++)
    {
        fr[a[i - k]]++;
        if (fr[a[i - k]] == 1) cnt++;
        fr[a[i]]--;
        if (fr[a[i]] == 0) cnt--;
        if (nrMax < cnt) nrMax = cnt;
    }
    cout << nrMax << "\n";
    return 0;
}