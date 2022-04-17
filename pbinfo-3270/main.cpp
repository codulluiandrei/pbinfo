#include <iostream>
using namespace std;
int main() {
    long long int n, S = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            if (i % 2 == 0) S = S + i;
            if (n / i % 2 == 0) S = S + n / i;
        }
        if (i * i == n && i % 2 == 0) S = S - i;
    } cout << S;
    return 0;
}
