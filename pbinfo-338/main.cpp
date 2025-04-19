#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long int S = 0, P;
    for (int i = 1; i <= n; ++i) {
        P = 1;
        for (int j = 1; j <= i; ++j)
            P = P * i;
        S = S + P;
    } cout << "Rezultatul este " << S;
    return 0;
}