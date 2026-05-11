#include <bits/stdc++.h>
using namespace std;
int a[100003], n, k;
int fr[100003];
int main()
{
    int i, j, nrD = 0;
    long long cnt = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    j = 1;
    for (i = 1; i <= n; i++)
    {
        fr[a[i]]++;
        if (fr[a[i]] == 1) nrD++;
        while (nrD >= k)
        {
            cnt += (n - i + 1);
            fr[a[j]]--;
            if (fr[a[j]] == 0) nrD--;
            j++;
        }
    }
    cout << cnt << "\n";
    return 0;
}