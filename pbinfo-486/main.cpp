#include <iostream>
using namespace std;
int main() {
    int v[1001], n, maxim = -1, minim = 1000001;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        if (v[i] > maxim)
            maxim = v[i];
        if (v[i] < minim)
            minim = v[i];
    } cout << minim << " " << maxim;
    return 0;
}