#include <iostream>
using namespace std;
int main() {
    float v, dkm; 
    int d, t;
    cin >> v >> d;
    dkm = d / 1000.0;
    t = 60 * dkm / v;
    if (t != 60 * dkm / v)
        t++;
    cout << t;
    return 0;
}