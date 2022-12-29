#include <iostream>
using namespace std;
int main() {
    long long int n, temp, m, nrcifre = 0;
    bool adv = 0;
    cin >> n;
    m = n;
    while (m != 0) 
        nrcifre++, m = m / 10;
    nrcifre = nrcifre / 2;
    long long int p = 10;
    while (nrcifre--) {
        temp = n;
        int c = temp % p;
        while (temp && c == temp % p)
            temp = temp / p;
        if(temp == 0) adv = 1;
        p = p * 10;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}