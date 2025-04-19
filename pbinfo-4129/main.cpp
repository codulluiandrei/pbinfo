// Cristian Francu 2022-03-12
#include <stdio.h>
#define MAXN 100000
int inalt[MAXN + 1];
int main() {
  FILE *fin, *fout;
  int n, c, p, s, minh, maxh, i, t, d, dt, r, ph, rez;
  fin = fopen( "inundatie.in", "r" );
  fscanf( fin, "%d%d%d%d%d", &c, &n, &p, &s, &inalt[0] );
  minh = maxh = inalt[0];
  for ( i = 1; i < n; i++ ) {
    fscanf( fin, "%d", &inalt[i] );
    if ( inalt[i] > maxh )
      maxh = inalt[i];
    else if ( inalt[i] < minh )
      minh = inalt[i];
  }
  inalt[n] = maxh + 2; // pentru a nu fi aleasa la punctul 3
  fclose( fin );
  if ( c == 1 )
    rez = maxh - minh;
  else if ( c == 2 ) { // cerinta 2: dupa cate secunde apa ajunge la p?
    t = 0;
    i = p - 2;
    maxh = inalt[p - 1]; // inaltimea coloanei p
    for ( i = p - 2; i >= 0; i-- )
      if ( inalt[i] > maxh )
        maxh = inalt[i];
      else
        t += maxh - inalt[i];
    rez = t;
  } else if ( c == 3 ) { // cerinta 3: cea mai din dreapta coloana dupa s sec.
    dt = 0;
    d = 0;
    while ( d < n && s >= dt ) {
      s -= dt; // scadem delta t
      d++;
      dt = 0;
      ph = inalt[d - 1];
      // atentie! caz particular de testat: cand avem o inaltime foarte mare
      // care ar calcula prea mult in dt - depasire de timp
      // este esential sa puna a doua conditie, s >= dt
      while ( ph < inalt[d] && s >= dt ) {
        ph++;
        i = d - 1;
        while ( i >= 0 && inalt[i] < ph )
          i--;
        dt += d - 1 - i; // timpul in care apa ajunge la coloana d
        // printf( "d:%d  ph:%d  i:%d  dt:%d\n", d, ph, i, dt );
      }
    }
    rez = d; // d - 1 este coloana, dar +1 de la numerotarea de la 1
  } else {   // cerinta 4: coloana redusa cu 1 ca apa sa ajunga repede in p
    // atentie, caz particular: daca avem mai multe maxime consecutive egale
    // doar cel mai din dreapta merita redus, nu si celelalte.
    r = d = 0;
    // atentie, aici se poate gresi: sa nu ia in calcul chiar coloana p
    // r = --p; // pornim cu coloana p
    --p; // pornim cu coloana p
    do {
      maxh = inalt[p];
      i = p--;
      while ( p >= 0 && inalt[p] < maxh )
        p--;
      dt = i - p - 1;
      if ( dt >= d ) {
        d = dt;
        r = i;
      }
      // aici se poate gresi, trebuie sa mergem pana la o inaltime strict >
      // vor avea tendinta sa nu puna acest while
      while ( p >= 0 && inalt[p] <= maxh )
        p--;
    } while ( p >= 0 );
    rez = r + 1;
  }
  fout = fopen( "inundatie.out", "w" );
  fprintf( fout, "%d\n", rez );
  fclose( fout );
  return 0;
} 