#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    n = (n / 1000000) % 1000000;
    int Z = n % 100;
    n = n / 100;
    int L = n % 100;
    n /= 100;
    int A = n;
    if (A < 10) cout << 0;
    cout << A << " ";
    if (L < 10) cout << 0;
    cout << L << " ";
    if (Z < 10) cout << 0;
    cout << Z;
    return 0;
}