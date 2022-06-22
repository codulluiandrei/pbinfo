#include <bits/stdc++.h>
using namespace std;
ifstream in("parimpar2.in");
ofstream out("parimpar2.out");
int main() {
    int i, p; in >> i >> p;
    int temp, rezultat1 = 0, rezultat2 = -1;
    while (in >> temp) {
        if (temp % 2 == 1) {
            i--; if (i == 0) rezultat1 = temp;
        } else {
            p--; if (p == 0)
                rezultat2 = temp;
        }
    } if(rezultat1 == 0 || rezultat2 == -1) out << "Nu Exista";
    else out << rezultat2 << " " << rezultat1;
    return 0;
}