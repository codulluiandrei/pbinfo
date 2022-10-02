#include <iostream>
using namespace std;
bool pal(int n) {
    int copie = n, oglinda = 0;
    while (n > 0) {
        oglinda = oglinda * 10 + n % 10;
        n = n / 10;
    } n = copie;
    if (n == oglinda)
        return true;
    return false;
}
int main() {
    int temp, maxim = -1, counter = 0;
    bool adv = false;
    while (cin >> temp && temp != 0) {
        if (pal(temp)) {
            if (temp > maxim) {
                maxim = temp;
                counter = 1;
            } else if (temp == maxim) 
                counter++;
            adv = true;
        }
    } if (adv)
        cout << maxim << " " << counter;
    else 
        cout << "NU EXISTA";
    return 0;
}