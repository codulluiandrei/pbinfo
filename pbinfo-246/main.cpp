#include <iostream>
using namespace std;
int main() {
    int n, a = 0, b = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 != 0) {
            b = a;
            a = temp;
        }
    } if (a != 0&& b != 0) 
        cout << b << " " << a;
    else 
        cout << "Numere insuficiente";
    return 0;
}