#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a, b, contor = 0;
    bool adv = false;
    cin >> a >> b;
    for (int i = pow(10, a - 1); i <= pow(10, a) + 1; i++) {
        int copie = i, S = 0;
        while (copie > 0) {
            S = S + copie % 10;
            copie = copie / 10;
        } if (S == b) {
            cout << i << " ";
            contor++;
            adv = true;
        }
    } if (adv == false) 
        cout << 0;
    else  
        cout << "\n" << contor; 
    return 0;
}