#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n; cin >> n;
    int rad = (int) sqrt((double) n);
    if (n == rad * rad) cout << "da";
    else cout << "nu";
    return 0;
}