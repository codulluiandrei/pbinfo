/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    ll y = 0;
    ll p = 1;
    while (x > 0) {
        y += p * (x % 10 * 11);
        x /= 10;
        p *= 100;
    }
    cout << y << "\n";
    return 0;
}