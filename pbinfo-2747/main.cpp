#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double n, m, r;
    cin >> n >> m;
    r = log2(m) / log2(n);
    cout << r;
    return 0;
}