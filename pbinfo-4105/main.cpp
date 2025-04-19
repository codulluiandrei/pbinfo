#include <iostream>
using namespace std;
int v[1001], s[1001], n, contor;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int S = 0;
        cin >> v[i];
        for (int d = 1; d * d <= v[i]; d++)
            if (v[i] % d == 0) {
                S++;
                if (d * d != v[i]) S++;
            }
        s[i] = S;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (s[i] == s[j])
                contor++;
    cout << contor;
    return 0;
}