#include <iostream>
using namespace std;
int n, a, b, c, aux;
int main(){
    cin >> n;
    a = n % 10;
    b = n / 10 % 10;
    c = n / 100 % 10;
    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    } if (b > c) {
        aux = b;
        b = c;
        c = aux;
    } if (a > b) {
        aux = a;
        a = b;
        b = aux;
    } cout << a << " " << b << " " << c;
    return 0;
}
