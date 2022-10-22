#include <iostream>
using namespace std;
int main() {
    int n, k, maxim = 0, minim = 1000000, nrmaxim = 0, nrminim = 0, contor = 0;
    cin >> k >> n;
    while (n != 0) {
        contor++;
        if (n % 10 == k) {
            if (n > maxim) { 
                maxim = n;
                nrmaxim = contor;
            } if (n < minim) {
                minim = n;
                nrminim = contor; 
            }
        } cin >> n;
    } if (maxim == 0)
        cout << "NU EXISTA";
    else if (nrminim > nrmaxim)
		cout << nrminim - nrmaxim + 1;
	else 
        cout << nrmaxim - nrminim + 1;
    return 0;
}