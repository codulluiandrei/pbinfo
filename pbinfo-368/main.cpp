#include <iostream>
using namespace std;
int main() {
    int a, b, rez = 0;
    cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } for (int i = a; i <= b; i++) {
        int temp = i, oglinda = 0;
        while (temp > 0) {
            oglinda = 10 * oglinda + temp % 10;
            temp = temp /  10;
        } if (oglinda == i)
            rez++;
    } cout << rez;
    return 0;
}