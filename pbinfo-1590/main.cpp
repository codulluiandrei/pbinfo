#include <bits/stdc++.h>
using namespace std;
ifstream in("arma1.in");
ofstream out("arma1.out");
int v[10001], pr[50000], c[50000], fp[50000];
long long nivel, temp, S;
int verif_divi(int var1, int var2) {
    int temp;
    while (var2 != 0) {
        temp = var1 % var2;
        var1 = var2;
        var2 = temp;
    } return var1;
}
int verif_nivel(int d) { 
    int i, rez, p;
    rez = 0;
    for (i = 1; i <= temp && pr[i] * pr[i] <= d; i++){
        p = 0;
        while(d % pr[i] == 0) {
            p = p + 1;
            d = d / pr[i];
        } if (p != 0) {
            if (p == 1) return 1;
            else  rez = verif_divi(rez, p); 
        }
    } if(rez == 0 || d != 1) return 1;
    else return rez;
}
long long int verif_putere(long long int x, int p, int d) {
    long long int y = x, rez = 1;
    while (p > 1) {
        if (p % 2 == 1) rez = rez * y;
        y = y * y;
        if (y > d) return d + 1;
        p = p / 2;
    } return rez * y;
}
int verif_cantitate(int d, int p) {
    long long int x, y, ls, ld;
    if (p == 1) return d;
    x = d, y = 1;
    while (x > y) {
        x = (x + y) / 2;
        y = d / x;
    } if (p == 2) return x;
    ls = 1; ld = x;
    y = verif_putere(x,p,d);
    while (y != d) {
        if(y > d) ld = x;
        if(d > y) ls = x;
        x = ls + (ld - ls)/2;
        y = verif_putere(x,p,d);
    } return x;
}
void ciur() {
    long long i, j;
    temp = 0;
    pr[++temp] = 2;
    for (i = 3; i <= 48000; i = i + 2) {
        if (c[i] == 0) {
            pr[++temp] = i;
            for (j = i; j * i <= 48000; j = j + 2)
                c[i * j] = 1;
        }
    }
}
int main() {
    int C, n, i;
    ciur();
    in >> C >> n;
    for (i = 1; i <= n; i++) {
        in >> v[i];
        nivel = verif_nivel(v[i]);
        fp[i] = nivel;
    } if (C == 1) {
        S = 0; 
        for (i = 1; i <= n; i++)
            S = S + verif_cantitate(v[i], fp[i]);
        out << S;
    } else if (C == 2) 
        for (i = 1; i <= n; i++)
        out << fp[i] << "\n";
        return 0;
}
