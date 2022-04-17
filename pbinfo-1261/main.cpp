#include <iostream>
using namespace std;
int main() {
    int n, pare = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        if (n % 2 == 0) pare++;
    }
    if (pare == 0) cout << "NU EXISTA";
    else cout << pare;
    return 0;
}