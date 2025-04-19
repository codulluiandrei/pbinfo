// by Cristian Francu on 2022-03-30
#include <stdio.h>
#include <ctype.h>
char f1[10], f2[10], nr[10];
int main() {
  FILE *fin, *fout;
  int c, n, ncfd, nu, cfmax, nrmax, u, ch, m, i, cf, ucf, nrunif;
  fin = fopen( "siruri.in", "r" );
  fscanf( fin, "%d%d ", &c, &n );
  ncfd = nu = cfmax = nrmax = m = 0;
  nrunif = 1;
  ucf = 10;
  for ( i = 0; i < n; i++ ) {
    if ( (ch = fgetc( fin ) - '0') != (nrunif == 1 ? ucf : nr[m - 1]) ) {
      nrunif = 0;
      nu++;
      if ( m >= cfmax ) {
        if ( m > cfmax ) {
          cfmax = m;
          nrmax = 0;
        }
        nrmax++;
      }
      for ( cf = 1; cf < 10; cf++ )
        f2[cf] = 0;
      f2[nr[0] = ch] = m = 1;
    }
    ucf = ch;
    for ( cf = 1; cf < 10; cf++ )
      f1[cf] = 0;
    f1[ch] = 1;
    u = 1;
    while ( isdigit( ch = fgetc( fin )) ) {
      if ( f1[ch -= '0'] == 0 )
        f1[ch] = 1;
      else
        u = 0;
      if ( f2[ch] == 0 )
        f2[nr[m++] = ch] = 1;
      ucf = ch;
    }
    if ( u != 0 )
      ncfd++;
    nrunif++;
  }
  fclose( fin );
  if ( m >= cfmax ) {
    if ( m > cfmax ) {
      cfmax = m;
      nrmax = 0;
    }
    nrmax++;
  }
  fout = fopen( "siruri.out", "w" );
  if ( c == 1 )
    fprintf( fout, "%d\n", ncfd );
  else if ( c == 2 )
    fprintf( fout, "%d\n", nu );
  else
    fprintf( fout, "%d %d\n", cfmax, nrmax );
  fclose( fout );
  return 0;
} 