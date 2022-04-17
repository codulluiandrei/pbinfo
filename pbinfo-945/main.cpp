#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n, b, c; cin >> n >> b >> c;
    long long int nr = 1; int v1[10], temp = 0;
    while (n != 0) {
        v1[temp] = n % 10;
        n = n / 10;
        temp++;
    } nr = v1[temp - 1];
    for (int i = temp - 2; i >= 0; i--) {
        nr = nr * b + v1[i];    
    } temp = 0;
    int v2[100];
    while (nr != 0) {
        v2[temp] = nr%c;
        nr = nr / c;
        temp++;
    } for (int i = temp - 1; i >= 0; i--) cout << v2[i];
    return 0;
}