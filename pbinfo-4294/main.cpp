#include <iostream>
using namespace std;
int main() {
    int i, n;
    cin >> n;
    for (i = 1; i <= n / 2; i++)
        cout << i << " " << (n - i) << "\n";
    return 0;
}