#include <iostream>
#define nmax 100003
#define P 777013
using namespace std;
int ab[nmax], cd[nmax], n;
int main()
{
    int i;
    cin >> n;
    ab[1] = cd[1] = 2;
    for (i = 2; i <= n; i++)
    {
        ab[i] = (ab[i-1] + 2 * cd[i-1]) % P;
        cd[i] = (2 * ab[i-1] + 2 * cd[i-1]) % P;
    }
    cout << (ab[n] + cd[n]) % P << "\n";
    return 0;
}