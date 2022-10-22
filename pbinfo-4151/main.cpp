#include <iostream>
using namespace std;
int main() {
    int n, maxim = -1, minim = 1000000, pozmax = 0, pozmin = 0, v[10001];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] > maxim) {
            maxim = v[i];
            pozmax = i;
        }
        if (v[i] < minim) {
            minim = v[i];
            pozmin = i;
        }
    } if (pozmin > pozmax)
        for (int i = pozmax; i <= pozmin; i++) 
            cout << v[i] << " ";
    else
        for (int i = pozmin; i <= pozmax; i++)
            cout << v[i] << " ";
    return 0;
}