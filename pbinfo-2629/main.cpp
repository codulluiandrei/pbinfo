#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
int a[nmax], n;
unordered_map <int, int> M;
int main()
{
    int i, j, x, maxLen;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    maxLen = 0;
    j = 1;
    for (i = 1; i <= n; i++)
    {
        x = a[i];
        M[x]++;
        while (M[x] == 2)
        {
            M[a[j]]--;
            j++;
        }
        maxLen = max(maxLen, i - j + 1);
    }
    cout << maxLen << "\n";
    return 0;
}