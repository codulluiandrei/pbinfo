/*
 * Cmmdc - O(N*logN)
 * Bogdan Iordache
 * scor: 100
 */
#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1000005;
const int kMod = 1000000007;
int sum_multiple_pairs[kMaxN];
int sum_cmmdc_pairs[kMaxN];
int sum_multiples[kMaxN];
int main() {
    int N;
    cin >> N;
    // determinam pentru fiecare c, suma produselor de perechi de multipli
    for (int c = 1; c <= N; ++c) {
        // acest pas se poate rezolva in O(1) cu formule pentru suma de numere
        // consecutive, respectiv patrate consecutive, insa intrucat nu
        // afecteaza complexitatea pe mai departe, preferam metoda de mai jos
        // pentru a asigura o limita de timp mai robusta
        int simple_sum = 0;
        int squares_sum = 0;
        for (int a = c; a <= N; a += c) {
            simple_sum = (simple_sum + a) % kMod;
            squares_sum = (squares_sum + 1LL * a * a) % kMod;
        }
        sum_multiple_pairs[c] =
            (1LL * simple_sum * simple_sum % kMod - squares_sum + kMod) % kMod;
        sum_multiples[c] = (simple_sum + kMod - c) % kMod;
    }
    // idee: daca c divide perechea (a, b), fie c este cmmdc(a, b), fie c divide
    // cmmdc(a, b). Calculam in ordine descrescatoare pentru fiecare c suma
    // produselor de perechi pentru care c este cmmdc, scazand din suma de
    // perechi de multipli sumele de cmmdc ale tuturor multiplilor lui c. Acesta
    // este pasul care forteaza complexitatea de O(NlogN)
    for (int c = N; c; --c) {
        sum_cmmdc_pairs[c] = sum_multiple_pairs[c];
        for (int mc = 2 * c; mc <= N; mc += c)
            sum_cmmdc_pairs[c] =
                (1LL * sum_cmmdc_pairs[c] + kMod - sum_cmmdc_pairs[mc]) % kMod;
    }
    int res = 0;
    for (int c = 1; c <= N; ++c) {
        // scadem perechile de forma (m*c, c, c) sau (c, m*c, c)
        res = (res + 1LL * c *
                         (sum_cmmdc_pairs[c] -
                          2LL * c * sum_multiples[c] % kMod + kMod)) %
              kMod;
    }
    cout << res << endl;
    return 0;
} 