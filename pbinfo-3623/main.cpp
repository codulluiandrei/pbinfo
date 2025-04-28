#include <iostream>
#define M 1000000007;
using namespace std;
int n;
int pak(int b, int e)
{
    if(e == 0) return 1;
    if(e % 2 == 0)
    {
        int z;
        z = pak(b,e/2);
        return (1LL * z * z) % M;
    }
    return (1LL * b * pak(b,e-1)) % M;
}
int main()
{
    cin >> n;
    cout << (1LL * pak(2,n-1) * (n+1)) % M;
    return 0;
}