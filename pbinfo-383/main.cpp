#include <iostream>
using namespace std;
int main() {
    int n, k, v[222];
    cin >> k >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i) {
        int a = v[i] / k * k;
        int b = a + k;
        if (v[i] - a <= b - v[i]) v[i] = a;
        else v[i] = b;
    } for (int i = n - 1; i >= 0; -- i)
        cout << v[i] << " ";
    return 0;
}