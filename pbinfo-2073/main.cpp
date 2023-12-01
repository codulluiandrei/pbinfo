/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
int n, k, maxi, a[10001][103], l, x, y, smax = -1, elem = -1, s, cerinta;
void proces(int nr)
{
    int aux = a[nr][a[nr][0]];
    int j = a[nr][0]-1;
    while (aux > a[nr][j] && j)
        a[nr][j+1] = a[nr][j], j--;
    a[nr][j+1] = aux;
    while (a[nr][0] > k)
        a[nr][0]--;
}
int main()
{
    cin >> k >> n >> x;
    maxi = x;
    for (int i = 2; i <= n; i++)
    {
        cin >> y;
        maxi = max(maxi, y);
        if (x == y)
            l++;
        else
        {
            a[x][0]++;
            a[x][a[x][0]] = l;
            proces(x);
            l = 1;
        }
        x = y;
    }
    a[x][0]++;
    a[x][a[x][0]] = l;
    proces(x);
    for (int i = 0; i <= maxi; i++)
    {
        s = 0;
        for (int j = 1; j <= a[i][0]; j++)
            s += a[i][j];
        if (s >= smax)
            smax = s, elem = i;
    }
    cin >> cerinta;
    if (cerinta == 1)
        cout << smax;
    else
        cout << elem;
    return 0;
}
