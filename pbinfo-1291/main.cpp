#include <iostream>
using namespace std;
int n, v[10], m;
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        cout << v[i];
    cout << "\n";
}
bool testnr(int k) {
    if (k == 1) {
        if (v[k] != 0) return true;
        else return false;
    } if (abs(v[k] - v[k - 1]) < 2) return false;
    return true;
}
void backtracking(int k) {
    for (int i = 0; i < m; ++i) {
        v[k] = i;
        if (testnr(k)) {
            if (k == n) afisare(n);
            else backtracking(k + 1);
        }
    }
}
int main() {
    cin >> n >> m;
    backtracking(1);
    return 0;
}