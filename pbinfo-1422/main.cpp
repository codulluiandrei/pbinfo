#include <bits/stdc++.h>
using namespace std;
ifstream in("ograda.in");
ofstream out("ograda.out");
int main() {
    long long int x, capete, picioare;
    in >> x >> capete >> picioare;
    if (x == 1) {
        long long int gaini, vaci;
        vaci = (picioare - 2 * capete) / 2;
        gaini = capete - vaci;
        out << gaini << " " << vaci << endl;
    } else {
        long long imp = 0, par = 0;
        for (int i = 1; i * i <= picioare; i++)
            if (picioare % i == 0) {
                if (i % 2 == 0) par++;
                if (i * i < picioare)
                    if (picioare / i % 2 == 0)
                        par++;
            }
        for (int i = 1; i * i <= capete; i++)
            if (capete % i == 0) {
                if (i % 2 == 1) imp++;
                if (i * i < capete)
                    if (capete / i % 2 == 1) imp++;
            } out << imp << " " << par;
    } return 0;
}