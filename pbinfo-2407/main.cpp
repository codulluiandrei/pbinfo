#include <bits/stdc++.h>
using namespace std;
ifstream in("odaoni.in");
ofstream out("odaoni.out");
#define cin in
#define cout out
long long int counter = 0, i;
long long int n, cifn[11] = {0};
int main() {
    cin >> n;
    long long int copie = n;
    while (copie != 0) {
        cifn[copie % 10] = 1;
        copie = copie / 10;
    }
    for (i = 1; i * i < n; i++)
        if (n % i == 0) {
            copie = i;
            bool adv = true;
            while (copie != 0) {
                if (cifn[copie % 10] == 0)
                    adv = false;
                copie = copie / 10;
            } if (adv) 
                counter++;
            copie = n / i;
            adv = true;
            while (copie != 0) {
                if (cifn[copie % 10] == 0)
                    adv = false;
                copie = copie / 10;
            } if (adv) 
                counter++;
        } if (i * i == n) {
            copie = i;
            bool adv = true;
            while (copie != 0) {
                if (cifn[copie % 10] == 0)
                    adv = false;
                copie = copie / 10;
            } if (adv) 
                counter++;
        }
    cout << counter;
    return 0;
}