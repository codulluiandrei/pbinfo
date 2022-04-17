#include <bits/stdc++.h>
using namespace std;
int n, v[1005];
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i = i + 2)
        if (n % i == 0)
            return 0;
    return 1;
} int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int p = n; p >= 1; p--)
        if (prim(v[p]) == 1) {
            for (int i = p; i < n; i++)
                v[i] = v[i + 1];
            n--;
        } for (int i = 1; i <= n; i++)
    cout << v[i] << " ";
    return 0;
}
