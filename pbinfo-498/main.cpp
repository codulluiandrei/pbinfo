#include <bits/stdc++.h>
using namespace std;

int numararepie(int nr1, int nr2) {
    while(nr2 != 0) {
        int a = nr1 % nr2;
        nr1 = nr2;
        nr2 = a;
    } return nr1;
}

int main() {
    int n, C = 0, vec[205];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> vec[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (numararepie(vec[i], vec[j]) == 1) {
                C++;
            }
        }
    } cout << C;
    return 0;
}