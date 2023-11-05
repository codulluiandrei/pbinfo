#include <iostream>
using namespace std;
int main() {
    unsigned long long a, b, n, p = 1, k = 0;
    cin >> n >> a >> b;
    while (p<=b && k < n) {
        if (p >= a)
            cout << p << " ", k++;
        p = p * 2;
    } return 0;
}