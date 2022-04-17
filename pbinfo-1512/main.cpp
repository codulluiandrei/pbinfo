#include <iostream>
using namespace std;
long long int n, v[200001] = {0}, T, x, y, P, S = 0, smen[200002];
int main() {
    cin >> n >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> x >> y >> P;
        smen[x] = smen[x] + P;
        smen[y + 1] = smen[y + 1] - P;
    } for (int i = 1; i <= n; ++i) {
        S = S + smen[i];
        v[i] = v[i] + S;
        cout << v[i] << " ";
    } return 0;
}
