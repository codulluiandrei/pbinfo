#include <iostream>
using namespace std;

int x = 1, Z, L, A, z = 1, l = 1, a = 1900, zile[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool bisect(int x) {
    if (x % 4)
        return 0;
    if (x % 100)
        return 1;
    if (x % 400)
        return 0;
    return 1;
}

int main() {
    cin >> Z >> L >> A;
    for (; a < A; ++a) {
        if (bisect(a))
            x += 366;
        else
            x += 365;
    }
    for (; l < L; ++l) {
        if (bisect (A) && l == 2)
            x += 29;
        else
            x += zile[l];
    }
    x += Z - 1;
    x %= 7;
    if (x == 0)
        cout << "Duminica";
    else
        if (x == 1)
            cout << "Luni";
    else
        if (x == 2)
            cout << "Marti";
    else
        if (x == 3)
            cout << "Miercuri";
    else
        if (x == 4)
            cout << "Joi";
    else
        if (x == 5)
            cout << "Vineri";
    else
        if (x == 6)
            cout << "Sambata";
}
