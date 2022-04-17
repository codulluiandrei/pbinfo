#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, poz = 0, v[11]; cin >> n;
    while (n != 0) {
        v[++poz] = n % 10;
        n = n / 10;
    } for (int i = 1; i <= poz; i++) {
        for (int j = 1; j <= poz; j++)
            cout << v[j] << " ";
        cout << endl;
    } return 0;
}