#include <iostream>
using namespace std;
unsigned long long int n, temp;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        unsigned long long int val = temp / 2;
        int a = val, b = val + 1, c = 2 * val + 1;
        bool adv = false;
        if (a % 3 == 0) {
            a = a / 3;
            adv = true;
        } if (b % 3 == 0 && adv == false) {
            b = b / 3;
            adv = true;
        } if (c % 3 == 0 && adv == false) {
            c = c / 3;
            adv = true;
        } cout << (unsigned long long int) 2 * a * b * c + (temp * (temp + 1) / 2) * (temp % 2) << " ";
    } return 0;
}