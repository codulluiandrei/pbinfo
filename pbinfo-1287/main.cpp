#include <iostream>
using namespace std;
int n, v[10], a, b;
void afisare(int k) {
    for(int i = 1; i <= k; ++i)
        cout << v[i];
    cout << "\n";
}
void backtracking(int k) {
    for(int i = a; i <= b; ++i) {
        v[k] = i;
        if (k == n) afisare(k);
        else backtracking(k + 1);
    }
}
int main() {
    cin >> a >> b >> n;
    backtracking(1);
    return 0;
}
