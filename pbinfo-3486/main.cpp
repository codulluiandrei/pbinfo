#include <bits/stdc++.h>
using namespace std;
ifstream f("factorulx.in");
ofstream g("factorulx.out");
int factorx(int n) // descompunere in factori
{
    long long P = 1;
    if(n % 2 == 0)
    {
        P *= 2;
        while (n % 2 == 0) n >>= 1;
    }
    for (int i = 3; i * i <= n; i += 2)
        if(n % i == 0) {
        P *= i;
        while (n % i == 0) n = n / i;
    }
    if (n > 2) P *= n;
    return P;
}
int n; // numarul de numere citite
int v[1024]; // vectorul in care preluam numerele citite
int fact[524288]; // vectorul in care se vor afla factorii-x
int main() {
    int i, j, m, k = 0, P;
    f >> n;
    for (i = 1; i <= n; i++) f >> v[i];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++) {
            m = __gcd(v[i] , v[j]); // cel mai mare divizor comun
            P = factorx(m); // factorul-x
            if (!binary_search(fact + 1, fact + k + 1, P)) { // P nu a fost adaugat pana acum in sirul factorilor x
                fact[++k] = P;
                sort(fact + 1, fact + k + 1);
            }
        }
    g << k << '\n';
    sort(fact + 1, fact + k + 1);
    for (i = 1; i <= k; i++) g << fact[i] << " ";
    f.close();
    g.close();
    return 0;
}