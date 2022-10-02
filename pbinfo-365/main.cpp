#include <iostream>
using namespace std;
int main() {
    int a, b;
    bool adv = false;
    cin >> a >> b;
    while (a > 0) {
        int v = a % 10, temp = b;
        while (b) {
            if (b % 10 == v)
                adv = true;
            b = b / 10;
        } b = temp;
        a = a / 10;
    } if (adv)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}