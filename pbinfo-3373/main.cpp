#include <bits/stdc++.h>
using namespace std;
ifstream in("culori.in");
ofstream out("culori.out");
#define cin in
#define cout out
int cer, n, k, m, v[10001];
int x, y, z, b[10001];
int main() {
    cin >> cer >> k >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    if (cer == 1) {
        for (int i = 1; i <= m; i++)
            cin >> x >> y >> z;
        int maxim = 0, lungime = 0;
        for (int i = 2; i <= n; i++) {
            if (v[i] == v[i - 1]) lungime++;
            else {
                if (lungime > maxim) 
                    maxim = lungime;
                lungime = 0;
            }
        } cout << maxim + 1;
    } else if (cer == 2) {
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> z;
            b[x] = b[x] + z;
            b[y + 1] = b[y + 1] - z;
        } for (int i = 1; i <= n; i++)
            b[i] = b[i - 1] + b[i];
        for (int i = 1; i <= n; i++)
            cout << v[i] + b[i] << " ";
    }
}