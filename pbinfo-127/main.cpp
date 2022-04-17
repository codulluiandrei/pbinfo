#include <bits/stdc++.h>
using namespace std;
int verifprim(int nr) {
    int temp;
    while (nr != 0) {
        temp = nr % 10;
        nr = nr / 10;
    } return temp;
} int main() {
    int n, v[1001], S = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        S = S + verifprim(v[i]);
    } cout << S;
}