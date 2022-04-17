#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long rezultat = 1;
    for (long long temp = 1; temp <= n; temp++) rezultat = rezultat * temp;
    cout << rezultat;
    return 0;
}