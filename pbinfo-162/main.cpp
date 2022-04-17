#include <iostream>
using namespace std;
int n, v[100];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int p = 1; p <= n; p++) {
        for (int i = 1; i <= n; i++) cout << v[i] << " ";
        cout << endl;
        int temp = v[1];
        for (int i = 1; i < n; i++) v[i] = v[i + 1];
        v[n] = temp;
    } return 0;
}
