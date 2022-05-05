#include <iostream>
using namespace std;
int n, v[10], cif[] = {2, 3, 5, 7};
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        cout << cif[v[i]];
    cout << "\n";
}
void backtracking(int k) {
	for (int i = 0; i < 4; ++i) {
        v[k] = i;
        if (k == n) afisare(k);
        else backtracking(k + 1);
    }
}
int main() {
    cin >> n;
    backtracking(1);
    return 0;
}