#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
    	long long putere = 1;
        for (int i2 = 1; i2 <= i; i2++)
            putere = 1LL * putere * i;
        S = S + putere;
    }
    cout << "Rezultatul este " << S;
    return 0;
}