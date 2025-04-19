#include <iostream>
using namespace std;
int main() {
    long long int n, cer, a, b, c; cin >> cer;
    cin >> n; int rez = n;
    if (cer == 1) {
        cin >> a >> b;
        rez = rez - (n / a) - (n / b);
        rez = rez + (n / (a * b));
    } else if (cer == 2) {
        cin >> a >> b >> c;
        rez = rez - (n / a) - (n / b) - (n / c);
        rez = rez + (n / (a * b)) + (n / (b * c)) + (n / (a * c));
        rez = rez - (n / (a * b * c));
    } cout << rez;
    return 0;
}