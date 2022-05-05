#include <iostream>
using namespace std;
int n, v[10], m;
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        cout << v[i];
    cout << "\n";
}
void backtracking(int k) {
    for (int i = 0; i < m; ++i) {
        v[k] = i;
        if (k > 1 || i > 0) {
            if (k == n) afisare(k);
            else backtracking(k + 1);
        }
    }
}
int main() {
    cin >> n >> m;
    backtracking(1);
    return 0;
}