#include <iostream>
using namespace std;
long long int n, k, x;
long long int nrcif = 0, scif = 0, r1, r2, rest;
int main() {
    cin >> n >> k;
    if (k == 1) rest = n % 72;
    else { x = n;
        while(x != 0) {
            nrcif++;
            scif = scif + x % 10;
            x = x / 10;
        } scif = scif * k;
        r1 = scif % 9;
        if (nrcif >= 3)
            r2 = (n % 1000) % 8;
        else if (nrcif == 2) 
            r2 = ((n % 10) * 100 + n % 100) % 8;
            else {
                if (k == 2) 
                    r2 = (11 * n) % 8;
                else 
                    r2 = (111 * n) % 8;
             }
        if (9 * r2 - 8 * r1 >= 0)
            rest = (9 * r2 - 8 * r1) % 72;
        else
            rest = (9 * r2 - 8 * r1 + 72) % 72;
    } cout << rest;
    return 0;
}