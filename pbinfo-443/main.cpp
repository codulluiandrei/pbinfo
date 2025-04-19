#include <iostream>
using namespace std;
int main() {
    long long int n, temp, S = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        int d = 3, f = -1;
        if (temp % 2 == 0) f = 2;
        while (f == -1)
            if (temp % d == 0)
            	f = d;
            else {
            d = d + 2;
            if (d * d > temp) f = temp;
        } S = S + f;
    } cout << S;
    return 0;
}