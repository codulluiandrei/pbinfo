/* Autor: Cristian Francu
 * Timp: O(N*S) - unde N este lungimea sirului si S este numarul de cifre (10)
 * Memorie: O(N + S) - approx 500KB
 *
 * Idee: la orice pozitie k vom a vea o pozitie spre dreapta unde apare primul
 * zero. Similar, unde apare primul 1, etc. Ne dorim sa stim care este
 * urmatoarea cifra dupa pozitia k care sa duca la un sir cat mai scurt. Pentru
 * aceasta vom porni de la dreapta la stanga, memorqnd un vector de 10 perechi
 * pentru fiecare cifra care este indicele primei aparitii catre dreapta si
 * care este lungimea minima a unui sir care incepe cu ea. Acest vector se
 * poate actualiza in O(S) cqnd trecem la urmatorul element. Pentru fiecare
 * element al sirului vom memora un indice al urmatoarei cifre ce duce la minim
 * La final parcurgem pointerii de minim contruind numarul minim.
 *
 * O alta descriere, de nivel avansat: construim pentru fiecare cifra din sir
 * un nod cu zece copii, cate unul pentru fiecare cifră. Pointerul zero este 
 * catre prima aparitie a lui zero spre dreapta, pointerul unu catre prima de
 * unu, etc. In acest DAG cea mai scurta cale de la radacina la o frunza este
 * numarul căutat. In realitate nu vom memora nodurile ci le vom procesa pe
 * masura ce le generam. Se ajunge la algoritmul descris mai sus.
 */
#include <stdio.h>
#define MAXN 100000
#define NRCF 10
char sir[1 + MAXN];
int minurm[1 + MAXN], minlen[NRCF], indcf[NRCF];
int main() {
  FILE *fin, *fout;
  int c, n, ch, i, cf, len, mlen;
  fin = fopen( "bug.in", "r" );
  fscanf( fin, "%d ", &c );
  n = 0;
  while ( (ch = fgetc( fin )) != '\n' )
    sir[++n] = ch - '0';
  fclose( fin );
  for ( i = n; i >= 0; i-- ) {
    mlen = MAXN + 1; // infinit
    for ( cf = (i == 0 ? 1 : 0); cf < NRCF; cf++ )
      if ( (len = (minlen[cf] == 0 ? 0 : 1 + minlen[cf])) < mlen )
        minurm[i] = (mlen = len) == 0 ? -cf : indcf[cf];
    minlen[sir[i]] = mlen == 0 ? 1 : mlen;
    indcf[sir[i]] = i;
  }
  fout = fopen( "bug.out", "w" );
  if ( c == 1 )
    fprintf( fout, "%d\n", mlen );
  else {
    i = minurm[0];
    while ( i > 0 ) {
      fputc( sir[i] + '0', fout );
      i = minurm[i];
    }
    fprintf( fout, "%d\n", -i );
  }
  fclose( fout );
  return 0;
}