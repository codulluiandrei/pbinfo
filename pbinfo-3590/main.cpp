#include <iostream>
using namespace std;
int main()
{
    unsigned long long x;
    cin >> x;
    cout << 64 - __builtin_clzll(x) - __builtin_ctzll(x);
    return 0;
}