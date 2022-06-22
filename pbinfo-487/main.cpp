#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, vec[1001], suma = 0, temp1 = 0, temp2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        suma += vec[i];
    } temp1 = suma / n;
    for (int i = 1; i <= n; i++) {
            if (vec[i] > temp1)   temp2++;
    }
    cout << temp2;
    return 0;
}