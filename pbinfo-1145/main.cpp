#include <bits/stdc++.h>
using namespace std;
ifstream in("extraprime.in");
ofstream out("extraprime.out");
long long int contor = 0, maxim = -1000000000, minim = 1000000000;
bool ciur[10000005];
int a, b, cifre[10], nrcif;
void fciur() {
    ciur[1] = 1;
    for (int i = 4; i <= 10000000; i = i + 2) ciur[i] = 1;
    for (int i = 3; i * i <= 10000000; i = i + 2)
        if (!(ciur[i]))
            for (int j = i * i; j <= 10000000; j = j + 2 * i)
        		ciur[j] = 1;
}
int verif(int n) {
    nrcif = 0;
    if (ciur[n]) return false;
    while (n != 0) {
        cifre[++nrcif] = n % 10;
        n = n / 10;
    } for (int i = nrcif; i >= 1; i--) {
        int temp = 0;
        for (int j = nrcif; j >= 1; j--)
            if (i != j)
            	temp = temp * 10 + cifre[j];
        if (ciur[temp]) return false;
    } return true;
}
int main() {
    fciur();
    in >> a >> b;
    for (int i = a; i <= b; i++) {
        int temp = i;
        if (verif(temp)) {
            if (temp > maxim) maxim = temp;
            if (temp < minim) minim = temp;
        	contor++;
        }
    } out << contor << "\n" << minim << "\n" << maxim;
    return 0;
}