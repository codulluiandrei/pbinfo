#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int minim1, minim2, minim3 = 100000;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if (temp < minim1) {
            minim3 = minim2;
            minim2 = minim1;
            minim1 = temp;
        } else if (temp < minim2) {
            minim3 = minim2;
            minim2 = temp;
        } else if (temp < minim3) {
            minim3 = temp;
        }
    } cout << minim3 << " " << minim2 << " " << minim1;
    return 0;
}