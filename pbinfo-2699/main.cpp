#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; long long int p;
    cin >> n >> p;
    for (long long int i = 1; i <= p; i = i * n) cout << i << " ";
    return 0;
}