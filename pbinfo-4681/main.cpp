#include <iostream>
using namespace std;
int a[55][55], n;
int main()
{
    int i, j, x;
    /// citire
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            while (x % 3 == 0) x /= 3;
            while (x % 5 == 0) x /= 5;
            a[i][j] = x;
        }
    /// afisare
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}