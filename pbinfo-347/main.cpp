#include <iostream>
using namespace std;
int main() {
    int n, temp, maxim, minim;
    cin >> n;
    cin >> temp;
    minim = maxim = temp;
    for (int i = 2; i <= n; ++i) {
        cin >> temp;
        if (temp > maxim) maxim = temp;
        if (temp < minim) minim = temp;
    } cout << maxim + minim;
    return 0;
}
