#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int pi(int n) {
    int rez = 0;
    if (n % 2 == 0) {
        int ind = 1;
        while (n > 0) {
            if (n % 10 % 2 == 0) {
                rez = rez + n % 10 * ind;
                ind = ind * 10;
            } n = n / 10;
        }
    } else {
        int ind = 1;
        while (n > 0) {
            if (n % 10 % 2 == 1) {
                rez = rez + n % 10 * ind;
                ind = ind * 10;
            } n = n / 10;
        }
    } return rez;
}
int main() {
    int a, b;
    cin >> a >> b;
    if (pi(a) > pi(b))
        cout << a;
    else if (pi(a) < pi(b))
        cout << b;
    else if (pi(a) == pi(b))
        if (a > b) 
            cout << a;
        else 
            cout << b;
    return 0;
}