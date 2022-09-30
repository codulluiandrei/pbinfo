#include <bits/stdc++.h>
using namespace std;
ifstream in("benzinarii.in");
ofstream out("benzinarii.out");
#define cin in
#define cout out
long long int n, minim = 1000000001, dist1 = 0, dist2 = 0;
bool adv = true;
bool palindrom(int n) {
    long long int oglinda = 0, copie = n;
    while (copie != 0) {
        oglinda = oglinda * 10 + copie % 10;
        copie = copie / 10;
    } if (oglinda == n)
        return true;
    else 
        return false;
}
int main() {
    cin >> n;
    long long int copie = n;
    while (adv != false) {
        dist1++;
        if (palindrom(copie + 1) == true)
            adv = false;
        else 
            copie++;
    } copie = n; 
    if (dist1 < minim)
        minim = dist1;
    adv = true;
    while (adv != false) {
        dist2++;
        if (palindrom(n - 1) == true) 
            adv = false;
        else 
            n--;
    } if (dist2 < minim)
        minim = dist2;
    cout << minim << " " << minim + copie;
    return 0;
}