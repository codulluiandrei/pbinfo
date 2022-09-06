#include <iostream>
using namespace std;
int main() {
    long long int n, var = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp, maxim = 0;
        cin >> temp;
        while (temp > 0) {
            int cif = temp % 10;
            if (cif > maxim) 
                maxim = cif;
            temp = temp / 10;
        } var = var * 10 + maxim;
    } cout << var * var;
    return 0;
}