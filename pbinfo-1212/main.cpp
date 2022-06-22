#include <iostream>
using namespace std;
long long n, m, r, a, b, c, rez;
int main() {
    cin >> n;
    m = 10234573;
    r = n % 6;
    switch (r) {
        case 0: a = (n / 6) % m;
                b = (n + 1) % m;
                c = (2 * n + 1) % m;
                break;
        case 1: a = n % m;
                b = (( n + 1 ) / 2) % m;
                c = (( 2 * n + 1 ) / 3) % m;
                break;
        case 2: a = (n / 2) % m;
                b = ((n + 1 ) / 3) % m;
                c = (2 * n + 1) % m;
        		break;
        case 3: a = (n / 3) % m;
                b = (( n + 1) / 2) % m;
                c = (2 * n + 1) % m;
        		break;
        case 4: a = (n / 2) % m;
                b = (n + 1) % m;
                c = ((2 * n + 1) / 3) % m;
        		break;
        case 5: a =  n % m ;
                b = ((n + 1 ) / 6) % m;
                c = (2 * n + 1) % m;
                break;
    } rez = (a * b) % m;
    rez = (rez * c) % m;
    cout << rez;
    return 0;
}