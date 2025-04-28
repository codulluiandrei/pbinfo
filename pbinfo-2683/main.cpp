#include <iostream>
#define nmax 1003
using namespace std;
int a[nmax];
int n, d[nmax], k;
/// d[i]=capatul celui de-al i-lea subsir
int main()
{
    int i, j, x;
    cin >> n;
    k = 0;
    d[0] = 1e9;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        if (x <= d[k]) d[++k] = x;
        else
        {
            for (j = 1; d[j] >= x; j++)
                ;
            d[j] = x;
        }
    }
    cout << k << "\n";
    return 0;
}