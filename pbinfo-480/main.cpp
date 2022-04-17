#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n % 3 != 0) cout << "NU EXISTA";
    else cout << n / 3 - 1 << " " << n / 3 << " " << n / 3 + 1;
    return 0;
}