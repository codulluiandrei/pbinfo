#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a + b > 100)
        cout << a + b - 100;
    else cout << 0;
    return 0;
}