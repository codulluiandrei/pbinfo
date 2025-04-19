#include <assert.h>
#include <stdio.h>
#define MAX_N 100000
#define MAX_M 100000
#define MAX_PRIMES 6
#define MOD 1000000009
#define HALF 500000005
struct {
  int val, sign;
} divisors[1 << MAX_PRIMES];
int p[MAX_PRIMES + 1];
int f[MAX_M + 1];
int pf[MAX_M + 1], quot[MAX_M + 1];
int multiples[MAX_M + 1];
int coprime_range[MAX_M + 1];
int n, m;
// Calculeaza p^e % MOD prin ridicari la patrat.
int fast_exp(int p, int e) {
  long long result = 1;
  while (e) {
    if (e & 1) {
      result = result * p % MOD;
    }
    p = (long long)p * p % MOD;
    e >>= 1;
  }
  return result;
}
// Calculeaza ciurul lui Eratostene pina la M (cel mai mic divizor si citul).
void precompute_sieve() {
  for (int i = 1; i <= m; i++) {
    pf[i] = i;
    quot[i] = 1;
  }
  for (int p = 2; p * p <= m; p++) {
    if (pf[p] == p) { // p este prim
      for (int c = p * p; c <= m; c += p) {
        if (pf[c] == c) {
          pf[c] = p;
          quot[c] = c / p;
        }
      }
    }
  }
}
// Colecteaza divizorii lui x in divisors[] si returneaza numarul lor.
// Ignora multiplicitatea factorilor primi.
int collect_divisors(int x) {
  // Colecteaza divizorii primi ai lui x in p[].
  int num_primes = 0;
  while (x != 1) {
    if (!num_primes || pf[x] != p[num_primes - 1]) {
      p[num_primes++] = pf[x];
    }
    x = quot[x];
  }
  // Itereaza prin toate combinatiile posibile de divizori. Ca sa obtinem
  // O(2^num_primes) si nu O(num_primes * 2^num_primes), folosim incrementarea
  // unui contor binar.
  int prod = 1, sign = 1;
  for (int mask = 0; mask < (1 << num_primes); mask++) {
    divisors[mask] = { prod, sign };
    int bit = 0;
    while (mask & (1 << bit)) {
      prod /= p[bit++];
      sign = -sign;
    }
    prod *= p[bit];
    sign = -sign;
  }
  return 1 << num_primes;
}
// Pentru fiecare valoare x, calculeaza citi multipli de x exista la intrare.
void precompute_multiples() {
  for (int i = 1; i <= m; i++) {
    if (f[i]) {
      // Cele f[i] valori de i sint multipli pentru toti divizorii lui i.
      int num_divisors = collect_divisors(i);
      for (int j = 0; j < num_divisors; j++) {
        multiples[divisors[j].val] += f[i];
      }
    }
  }
}
// Pentru fiecare 1 <= i <= m, calculeaza numarul de numere coprime cu i din
// [1, m].
void precompute_coprime_ranges() {
  for (int i = 1; i <= m; i++) {
    int num_divisors = collect_divisors(i);
    for (int j = 0; j < num_divisors; j++) {
      coprime_range[i] += divisors[j].sign * (m / divisors[j].val);
    }
  }
}
// Calculeaza numarul de perechi coprime dintre valorile impuse.
int count_assigned_coprimes() {
  long long result = -f[1]; // Fiecare 1 greseste cu 1.
  for (int i = 1; i <= m; i++) {
    if (f[i]) {
      int coprimes = 0;
      int num_divisors = collect_divisors(i);
      for (int j = 0; j < num_divisors; j++) {
        coprimes += divisors[j].sign * multiples[divisors[j].val];
      }
      result += (long long)coprimes * f[i];
    }
  }
  result %= MOD;
  result = result * HALF % MOD;
  result = result * fast_exp(m, f[0]) % MOD;
  return result;
}
// Calculeaza numarul de perechi coprime pe care le putem obtine intre oricare
// doua zerouri.
int count_unassigned_coprimes() {
  long long result = 0;
  if (f[0] > 1) {
    for (int i = 1; i <= m; i++) {
      result += coprime_range[i];
    }
    result %= MOD;
    result = result * ((long long)f[0] * (f[0] - 1) / 2 % MOD) % MOD;
    result = result * fast_exp(m, f[0] - 2) % MOD;
  }
  return result;
}
// Calculeaza numarul de perechi coprime pe care le putem obtine intre un zero
// si o valoare impusa.
int count_mixed_coprimes() {
  long long result = 0;
  if (f[0]) {
    for (int i = 1; i <= m; i++) {
      if (f[i]) {
        result += (long long)f[i] * coprime_range[i];
      }
    }
    result %= MOD;
    result = result * f[0] % MOD;
    result = result * fast_exp(m, f[0] - 1) % MOD;
  }
  return result;
}
int main() {
  // Citeste datele de intrare.
  FILE* file = fopen("countall.in", "r");
  fscanf(file, "%d %d", &n, &m);
  for (int i = 0; i < n; i++)  {
    int x;
    fscanf(file, "%d", &x);
    f[x]++;
  }
  fclose(file);
  precompute_sieve();
  precompute_multiples();
  precompute_coprime_ranges();
  // Numara cele trei categorii de perechi.
  int result = ((long long)count_assigned_coprimes() +
                count_unassigned_coprimes() +
                count_mixed_coprimes()
                ) % MOD;
  // Scrie rezultatul.
  file = fopen("countall.out", "w");
  fprintf(file, "%d\n", result);
  fclose(file);
  return 0;
}
// Denumim valorile nenule de la intrare "valori impuse”, iar zerourile
// "valori libere". Fie Z numarul de zerouri. Precalculam urmatoarele valori
// ajutatoare:
//
// 1. Vectorul de frecvente f al numerelor de la intrare. (Nota: Z = f[0]).
//
// 2. Ciurul lui Eratostene pina la M. Pentru fiecare numar X calculam pf[X] =
// cel mai mic factor prim al lui X. Pentru a reduce din impartiri, retinem si
// quot[X] = X / pf[x].
//
// Cu ciurul putem genera toti divizorii lui X, ignorind multiplicitatea
// factorilor primi. Pentru X = 84 = 2^2 * 3 * 7 generam 1, 2, 3, 7, 6, 14, 21
// si 42. Putem face acest lucru in O(2^max_factori_primi), unde
// max_factori_primi este 64. Suplimentar, pentru fiecare divizor generam un
// numar ±1 care retine paritatea numarului de factori primi. Pentru 84,
// divizorii 1, 6, 14 si 21 primesc semnul +1, iar ceilalti primesc -1.
//
// 3. Multiplii. Pentru fiecare valoare 1 <= X <= M, calculam citi multipli de
// X exista la intrare. Facem asta descompunindu-l pe X si incrementind
// numarul de multipli pentru divizorii lui.
//
// Cu (2) si (3) putem raspunde rapid la intrebarea: dat fiind X, cite valori
// impuse coprime cu X exista? Folosim principiul includerii si excluderii.
// Valorile impuse coprime cu 84 sint toate numerele (N), minus cele
// divizibile cu 2 sau 3 sau 7, plus cele divizibile cu 6 sau 14 sau 21, minus
// cele divizibile cu 42.
//
// 4. Informatia de coprimalitate pe domeniu. Pentru fiecare 1 <= X <= M,
// calculam coprime_range[X] = numarul de numere coprime cu X din [1, M]. Din
// nou folosim informatiile (2) si (3) si principiul includerii si excluderii.
// Valorile coprime cu 84 sint toate (M), minus M/2, M/3 si M/7, plus M/6,
// M/14 si M/21, minus M/42 (toate rotunjite in jos).
//
// Acum putem raspunde la intrebari. Perechile coprime pot proveni din trei
// surse:
//
// A. Doua valori impuse.
// B. Doua valori libere.
// C. O valoare impusa si una libera.
//
// A. Pentru fiecare V[i] de la intrare raspundem la intrebarea "cite valori
// impuse coprime cu V[i] exista?" si insumam raspunsurile.
//
// B. Exista M^Z completari posibile care genereaza M^Z * C(Z, 2) perechi a
// caror coprimalitate trebuie sa o decidem. Orice pereche (P, Q) are la fel
// de multe aparitii ca orice alta pereche (nu exista valori preferate).
// Asadar, perechea (P, Q) are M^(Z-2) * C(Z,2) aparitii. Daca il fixam pe P
// si insumam valorile pentru toate Q-urile posibile, numarul de perechi
// coprime va fi M^(Z-2) * C(Z,2) * coprime_range[P]. Asadar, raspunsul este
// M^(Z-2) * C(Z,2) * sum_{P=1}^{M} coprime_range[P].
//
// C. Similar, exista M^Z completari posibile care genereaza M^Z * Z
// valori. Orice valoare P are la fel de multe aparitii, deci fiecare valoare
// apare de M^(Z-1) * Z ori. Acum pentru o valoare impusa V[i], stim ca
// raspunsul va fi coprime_range[V[i]] * M^(Z-1) * Z.