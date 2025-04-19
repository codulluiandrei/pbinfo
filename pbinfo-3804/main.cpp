#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c && b + c >= a && a + c >= b) {
        double sp = (a + b + c) / 2;
        double raza = (sqrt(sp * (sp - a) * (sp - b) * (sp - c)) / sp) * 100;
        if ((int) raza % 10 == 0) {
            if ((int) raza / 10 % 10 == 0)
                cout << (int) raza / 100 << ".00";
            else
                cout << (int) raza / 100 << "." << (int) raza / 10 % 10 << "0";
        } else
            cout << (int) raza / 100 << "." << (int) raza / 10 % 10 << (int) raza % 10;
    } else
        cout << "Imposibil";
    return 0;
}