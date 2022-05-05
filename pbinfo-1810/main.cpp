#include <iostream>
using namespace std;
int n, v[21];
int testnr(int n) {
    if (n < 0) n = -n;
    return n;
}
void afisare() {
    for (int i = 1; i <= n; i++)
        cout << v[i];
    cout << "\n";
}
void backtracking(int k) {
    for (int i = 0; i <= n / 2; i++) {
        v[k] = i;
        if (v[1] == 0 && (k == 1 || testnr(v[k] - v[k - 1]) == 1))
            if (k == n) {
				if(v[n] == 0) afisare();
        	} else backtracking(k + 1);
    }
}
int main() {
    cin >> n;
    backtracking(1);
    return 0;
}