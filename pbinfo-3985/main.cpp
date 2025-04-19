#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, S = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int temp;
        cin >> temp;
        if (temp < 100 && temp > 9)
            S = S + temp;
    } cout << S;
    return 0;
}