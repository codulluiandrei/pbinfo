#include <iostream>
using namespace std;
bool prim(int a) {
    if (a < 2) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;
    for (int d = 3; d * d <= a; d = d + 2)
        if (a % d == 0)
            return false;
    return true;
}
int main() {
    int n, counter = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (prim(temp))
            counter++;
    } cout << counter;
    return 0;
}