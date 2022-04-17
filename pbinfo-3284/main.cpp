#include <iostream>
using namespace std;
int maxim = -100, minim = 1000000001, n, temp;
int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        if (i % 2 == 0)
            if (temp > maxim)
                maxim = temp;
        if (i % 2 == 1)
            if (temp >= 10 && temp <= 99 && temp < minim)
                minim = temp;
    } cout << maxim << " ";
    if (minim != 1000000001) cout << minim;
    else cout << "-1";
    return 0;
}