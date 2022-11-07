#include <iostream>
using namespace std;
int main() {
    int n, v[100000], var, minim1 = 0, minim2 = 1000000000;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i + 1]) < abs(minim1 - minim2)) {
            minim1 = v[i];
            minim2 = v[i + 1];
        } else if (abs(v[i] - v[i + 1]) == abs(minim1 - minim2) && minim1 + minim2 > v[i] + v[i + 1]) {
            minim1 = v[i];
            minim2 = v[i + 1];
        }
    } cout << minim1 << " " << minim2;
    return 0;
}
