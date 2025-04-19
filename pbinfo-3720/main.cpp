/* Autor: Tulba-Lecu Theodor-Gabriel
 * Complexitate: O(log(N))
 * Implementare: Formula
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    bool first = true;
    int N, V, mod1 = 0, mod2 = 0, mod3 = 0;
    FILE *in = fopen("aproape.in", "r");
    FILE *out = fopen("aproape.out", "w");
    fscanf(in, "%d %d", &V, &N);
    do {
        if (N < 10) {
            if (N <= 1 || N == 9) {
                if (N == 1 && first) {
                    mod2++;
                } else {
                    mod1++;
                }
            } else
                mod2++;
            if (N <= 2 || N >= 8) {
                if (N == 2 && first) {
                    mod3 += 2;
                } else {
                    mod3++;
                }
            } else
                mod3 += 2;
        } else {
            if (N % 10 == 0 || N % 10 == 9)
                mod1++;
            else
                mod2++;
            if (N % 10 <= 1 || N % 10 >= 8)
                mod3++;
            else
                mod3 += 2;
        }
        N /= 10;
        first = false;
    } while (N > 0);
    if (V == 1) {
        fprintf(out, "%d\n", mod1 + mod2);
    } else if (V == 2) {
        fprintf(out, "%d\n", mod1 + 2 * mod2);
    } else {
        // {numarul n} + numerele in care schimbam o singrua cifra cu 2 +
        // numarul de numere in care schimbam 2 cifre (perechile ordonate
        // cu o singura optiune + 2 * perechile ordonate prima cu o optiune, a
        // doua cu 2 optiuni + 4 * perechile ordonate de cifre cu 2 optiuni)
        fprintf(out, "%d\n",
                1 + mod3 + mod1 * (mod1 - 1) / 2 + 2 * mod2 * (mod2 - 1) +
                    2 * mod1 * mod2);
    }
    return 0;
}