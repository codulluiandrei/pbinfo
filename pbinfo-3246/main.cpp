#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    long long int S = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        n = i;
        int temp = 0, var = 0;
        while (n > 0) {
            if (n % 2 == 0) var++;
            else temp++;
            n = n / 10;
        } if (temp == var) S = S + i;
    } cout << S;
    return 0;
}