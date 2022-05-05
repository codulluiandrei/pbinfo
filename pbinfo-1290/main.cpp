#include <iostream>
using namespace std;
int n, v[10], m;
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        cout << v[i];
    cout << "\n";
}
void backtracking(int k) {
    if (k == n) {
        v[k] = v[1];
        afisare(k);
    } else for (int i = 0; i < m; ++i) {
            v[k] = i;
            if (k > 1 || i > 0)
                backtracking(k + 1);
        }
}
int main() {
    cin >> n >> m;
    backtracking(1);
    return 0;
}