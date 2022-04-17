#include <iostream>
using namespace std;
int k = 0, n, v[11];
int main() {
    cin >> n;
    while (n != 0) {
        k++;
        v[k] = n % 16;
        n = n / 16;
    } for (int i = k; i >= 1; i--)
        if (v[i] < 10) cout << v[i];
        else {
        if (v[i] == 10) cout << 'A';
        if (v[i] == 11) cout << 'B';
        if (v[i] == 12) cout << 'C';
        if (v[i] == 13) cout << 'D';
        if (v[i] == 14) cout << 'E';
        if (v[i] == 15) cout << 'F';
    } return 0;
}
