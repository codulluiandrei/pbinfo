#include <iostream>
#include <algorithm>
using namespace std;
int a[100003], n;
int main()
{
    int i, nr;
    long long nrSecv = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    nr = 0;
    for (i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1]) nr++;
        else nr = 0;
        nrSecv += nr;
    }
    cout << nrSecv;
    return 0;
}