#include <iostream>
using namespace std;
int n, S = 0, contor = 0, v[205];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        if (v[i])
            S = S + v[i], contor++;
    S = S / contor;
    for (int i = 1; i <= n; ++i)
        if (!v[i]) v[i] = S;
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
}