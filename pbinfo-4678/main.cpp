#include <iostream>
using namespace std;
int a[55][55], n, m, fr[1001];
int main()
{
    int i, j, k;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            fr[a[i][j]]++;
        k = 0;
        for (j = 1; j <= 1000; j += 2)
            while (fr[j] > 0)
            {
                a[i][++k] = j;
                fr[j]--;
            }
        for (j = 0; j <= 1000; j += 2)
            while (fr[j] > 0)
            {
                a[i][++k] = j;
                fr[j]--;
            }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}