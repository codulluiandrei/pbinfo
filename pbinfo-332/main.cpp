#include <bits/stdc++.h>
using namespace std;

int calcul(int n) {
    if (n == 0) return 0;
    else return calcul(n - 1) + n * (n + 1);
}

int main() {
    int n; cin >> n;
    cout << "Rezultatul este" << " " << calcul(n);
    return 0;
}