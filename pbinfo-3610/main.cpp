#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n % 100 == 0) cout << n;
    else cout << (n + 100 - n % 100);
    return 0;
}