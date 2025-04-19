#include <bits/stdc++.h>
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
ifstream f ("nr_div_huge.in");
ofstream g ("nr_div_huge.out");
ull nr, n, k, m, nrp;
bitset < 31630 > ciur;
vector < ull > prime;
void Precalculare () { // se vor precalcula numerele prime intr-un vector pentru descompunerea in factori primi
    for (ull i = 3; i * i <= 31625; i += 2)
    if (ciur[i] == 0)
    for (ull j = i * i; j <= 31625; j += 2 * i)
    ciur[j] = 1;
    for (ull i = 3; i <= 31625; i += 2) if (ciur[i] == 0) prime.emplace_back (i), nrp ++;
}
ull nrdivkn (ull N) { // nu se va incrementa odata exponentul lui 2 daca k e par
    ull P = 1, p = 0, d;
    while (N % 2 == 0) {
        N /= 2;
        p ++;
    }
    p = (p * m) % mod;
    P = (P * p) % mod;
    for (d = 0; d < nrp && prime[d] * prime[d] <= N; ++d) {
        for (p = 0; N % prime[d] == 0; p ++, N /= prime[d]);
        if (p) {
            p = (p * m) % mod;
            p = (p + 1) % mod;
            P = (P * p) % mod;
        }
    }
    if (N > 1) {
        p = 1;
        p = (p * m) % mod;
        p = (p + 1) % mod;
        P = (P * p) % mod;
    }
    return P;
}
ull nrdivk1 (ull N) { // numarul de divizori pentru k + 1 daca k e par
    ull P = 1, p = 0, d = 0;
    while (N % 2 == 0) {
        N /= 2;
        p ++;
    }
    p ++;
    P = (P * p) % mod;
    for (d = 0; d < nrp && prime[d] * prime[d] <= N; ++d) {
        for (p = 0; N % prime[d] == 0; p ++, N /= prime[d]);
        if (p) {
            p = (p + 1) % mod;
            P = (P * p) % mod;
        }
    }
    if (N > 1) P = (P * 2) % mod;
    return P;
}
ull nrdivkn_2 (ull N) { // k impar
    ull P = 1, p = 0, d = 0;
    while (N % 2 == 0) {
        N /= 2;
        p ++;
    }
    p = (p * m) % mod;
    p = (p + 1) % mod;
    P = (P * p) % mod;
    for (d = 0; d < nrp && prime[d] * prime[d] <= N; ++d) {
        for (p = 0; N % prime[d] == 0; p ++, N /= prime[d]);
        if (p) {
            p = (p * m) % mod;
            p = (p + 1) % mod;
            P = (P * p) % mod;
        }
    }
    if (N > 1) {
        p = 1;
        p = (p * m) % mod;
        p = (p + 1) % mod;
        P = (P * p) % mod;
    }
    return P;
}
ull nrdivk1_2 (ull N) { // numarul de divizori pentru k + 1 daca k e impar
    ull P = 1, p = 0, d = 0;
    while (N % 2 == 0) {
        N /= 2;
        p ++;
    }
    P = (P * p) % mod;
    for (d = 0; d < nrp && prime[d] * prime[d] <= N; ++d) {
        for (p = 0; N % prime[d] == 0; p ++, N /= prime[d]);
        if (p) {
            p = (p + 1) % mod;
            P = (P * p) % mod;
        }
    }
    if (N > 1) P = (P * 2) % mod;
    return P;
}
void Solve (ull N, ull K) { // Rezolvare
    if (K % 2 == 0) {
        ull nr1 = nrdivkn (K);
        ull nr2 = nrdivk1 (K + 1);
        g << (nr1 * nr2) % mod << '\n';
    } else {
        ull nr1 = nrdivkn_2 (K);
        ull nr2 = nrdivk1_2 (K + 1);
        g << (nr1 * nr2) % mod << '\n';
    }
}
void Read_Solve () { // citire si rezolvare
    f >> nr;
    while (nr --) {
        f >> n >> k;
        m = n + 1;
        Solve (n, k);
    }
}
int main() {
    Precalculare ();
    Read_Solve ();
    return 0;
}