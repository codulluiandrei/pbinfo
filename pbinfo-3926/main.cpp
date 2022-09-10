#include <iostream>
using namespace std;
int main() {
    long long int n;
    bool adv = true; 
    cin >> n;
    long long int temp = n, nrcif = 0;
    while (temp > 0) {
        nrcif++;
        temp = temp / 10;
    } for (int i = 1; i < nrcif; i++) {
        int cif1 = n % 10;
        int cif2 = n / 10 % 10;
        if (cif1 % 2 == 0 && cif2 % 2 == 0)
            adv = false;
        else if (cif1 % 2 == 1 && cif2 % 2 == 1)
            adv = false;
        n = n / 10;
    } 
    if (adv == true)
        cout << "da";
    else 
        cout << "nu";
    return 0;
}