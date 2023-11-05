#include <iostream>
using namespace std;
int main() {
    int n, i = 1, S = 0;
    cin >> n;
    while (S <= n) {
        i++;
        S = i * (i - 1) / 2;
        int p = n - S;
        if (p > 0 && p % i == 0) {
            for (int j = 0; j < i; ++j)
                cout << p / i + j << " ";
            cout << "\n";
        }
    } return 0;
}