#include <bits/stdc++.h>
using namespace std;
bitset<200001> a, b;
int main()
{
    int x, cnt = 0;
    while (cin >> x)
    {
        if (a[x] == 0)
        {
            cnt++;
            a[x] = 1;
        }
        else
        {
            if (b[x] == 0) cnt--;
            b[x] = 1;
        }
    }
    cout << cnt;
    return 0;
}