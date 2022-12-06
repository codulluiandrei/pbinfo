#include <iostream>
using namespace std;
int func(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    } return a;
}
int main() {
    int n, nr = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (func(i, j) == 1)
                nr++;
    cout << nr;
    return 0;
}