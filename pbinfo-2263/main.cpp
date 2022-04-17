#include <bits/stdc++.h>
using namespace std;
int main() {
    int t1, t2, n, m, z;
    cin >> t1 >> t2 >> n >> m >> z;
    int a = t1 * n + t2 * m;
    int t = a * z;
    cout << t;
    return 0;
}