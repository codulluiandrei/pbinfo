/* Autor: Cristian Francu
 * Timp: O(N log log N)
 * Memorie: O(N) - approx 20MB
 *
 * Idee: cel mai mare numar prim din componenta unui numar triprim
 * este maxim N/6. De aceea calculam ciurul lui Eratostene pana la 65
 * milioane. Pentru optimizare vom folosi un bit per element si nu vom
 * stoca decat numerele impare. Memoria necesara pentru ciur: 4MB. Vom
 * colecta numerele prime in alt vector si apoi vom numara numerele
 * triprime in O(N) folosind doi indici.
 *
 * Nota importanta: calculul ciurului si colectarea numerelor intr-un
 * vector constituie 95% din timpul de executare. De aceea trebuie sa
 * ne concentram pe acesti algoritmi, nu pe numararea numerelor
 * triprime.
 */
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define DEBUG 0

#define MAXN 390000000
// ciur pana la MAXN/6, doar cu numere impare, pe biti, patru octeti pe int
// rezulta MAXN/384 intregi adica 1015626
#define MAXNPER384 1015626 
#define NPRIME 4000000     // numarul de numere prime pana la 65 000 000

unsigned ciur[MAXNPER384]; // ciur pe biti circa 4MB
int n, prime[NPRIME];      // aici memoram numerele prime circa 16MB

static inline int getBit( int x ) {
  int i = x >> 6; // 32 bits per intreg dar numai impare
  int o = (x >> 1) & 31; // offset in cadrul intregului

  return (ciur[i] >> o) & 1;
}

static inline void setBit( int x ) {
  int i = x >> 6;        // 32 bits per intreg
  int o = (x >> 1) & 31; // offset in cadrul intregului

  ciur[i] |= (((unsigned)1) << o);
}

int triprime( int x ) {
  int ntriprime, i, j, k;

  ntriprime = 0;
  i = 0;
  while ( i + 2 < n && prime[i] * prime[j = i + 1] * prime[k = i + 2] <= x ) {
    while ( prime[i] * prime[j] * prime[k] <= x )
      k++;

    k--; // ajustam k
    // pornim cautarea cu doi indici, j creste si k scade
    while ( k > j ) {     // cata vreme avem un k
      ntriprime += k - j; // adunam numarul de perechi
      j++;                // avansam j
      // scadem k pentru ca produsul sa redevina <= x
      while ( k > j && prime[i] * prime[j] * prime[k] > x )
        k--;
    }
    i++;
  }
  return ntriprime;
}

int main() {
  FILE *fin, *fout;
  int a, b, c, i, d, tria, trib;

  fin = fopen( "triprime.in", "r" );
  fscanf( fin, "%d%d", &a, &b );
  fclose( fin );

  // ciurul lui Eratostene pana la b / 6
  c = (b / 6) | 63; // vrem sa fie divizibil cu 64
  // ciurul lui Eratostene doar pentru numere impare
  for ( i = 3; i * i <= c; i += 2 )
    if ( getBit( i ) == 0 )
      for ( d = i * i; d <= c; d += 2 * i )
        setBit( d );

  // colectam numerele prime
  prime[n++] = 2; // stocam 2, este singurul numar prim par
  for ( i = 3; i <= c; i += 2 )
    if ( getBit( i ) == 0 )
      prime[n++] = i;
  prime[n] = c + 1; // santinela

  trib = triprime( b );
  tria = triprime( a - 1 );

  fout = fopen( "triprime.out", "w" );
  fprintf( fout, "%d\n", trib - tria );
  fclose( fout );

  return 0;
} 