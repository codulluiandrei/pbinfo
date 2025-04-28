#include <iostream>
using namespace std;
int a[51][51], m, n;
int main()
{
    int i, j, x, y;
    cin >> m >> n;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (j > 9) x = i * 100 + j;
            else x = i * 10 + j;
            if (i > 9) y = j * 100 + i;
            else y = j * 10 + i;
            a[i][j] = (x <= y ? x : y);
        }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}