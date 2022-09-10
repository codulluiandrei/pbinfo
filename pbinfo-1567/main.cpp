#include <iostream>
using namespace std;
int main() {
    int S = 0, temp;
    bool cif2 = false;
    do {
        cin >> temp;
        int oglinda = 0, copie = temp;
        if (temp > 9) {
            while (copie > 0) {
                oglinda = oglinda * 10 + copie % 10;
                copie = copie / 10;
            } S = S + oglinda % 10 * 10 + oglinda / 10 % 10;
            cif2 = true;
        }
    } while (temp != 0);
    if (cif2 == false) 
        cout << 0;
    else 
        cout << S;
    return 0;
}