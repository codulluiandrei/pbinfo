#include <iostream>
using namespace std;
int main() {
    int n, temp, maxim = 1, nrmaxim = 0;
    cin >> n;
    for(int i = 1; i <= n ; ++i) {
        cin >> temp;
        int nrfact = 0, d = 2, copie = temp;
        while (temp != 1) {
            if (temp % d == 0) {
                nrfact++;
                while (temp % d == 0)
                    temp = temp / d;
            } d++;
            if (d * d > temp && temp > 1) {
                temp = 1;
                nrfact++;
            }
        } if (nrfact > nrmaxim) {
            nrmaxim = nrfact;
            maxim = copie;
        } else if (nrfact == nrmaxim)
                if (copie < maxim)
                    maxim = copie;
    } cout << maxim << endl;
    return 0;
}