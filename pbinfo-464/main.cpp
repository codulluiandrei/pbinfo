#include <iostream>
using namespace std;
int pre(int n, int k) {
    int rez = 0;
    while (n > 0) {
        if (n % 10 == k) rez++;
        n = n / 10;
    } return rez;
}
int main() {
    int k, temp, counter = 0;
    cin >> k;
    while (cin >> temp && temp != 0)
        if (temp % 2 == 0)
            counter = counter + pre(temp, k);
    cout << counter;
    return 0;
}