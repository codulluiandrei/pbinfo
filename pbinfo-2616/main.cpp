#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long int a = n / 2,  b = m / 2;
    if (n % 2 == 1) a++;
    if (m % 2 == 1) b++;
    cout << a * b;
    return 0;
}