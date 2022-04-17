#include <iostream>
using namespace std;
int main() {
    int n, v[31];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        v[i] = i;
        v[i + n] = i;
    } for (int i = 1; i <= n; ++i) {
        for (int j = i; j < n + i; ++j)
        cout << v[j] << " ";
        cout << endl;
    } return 0;
}
