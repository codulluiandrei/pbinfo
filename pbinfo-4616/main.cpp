// Isabela Coman 2024 - complexitate O(NMAX) timp, O( NMAX * MMAX ) Memorie - 100 000 * 99 * 8
#include <fstream>
#include <iostream>
#define NMAX 100000                         // n maxim de jucatori
#define MMAX 99                             // n maxim de echipe
#define LM 2000000000                       // maxim de mutari ce pot fi facute de o echipa
using namespace std;
ifstream fin  ( "robotron.in" );
ofstream fout ( "robotron.out" );
struct player {
  int cp;                                   // cod planeta
  int pw;                                   // putere
}E[MMAX+1][NMAX+1];                         // maxim MMAX echipe a cu maxim NMAX membrii
int L, n[MMAX+1];                           // Lungimea traseului, n de membrii ai fiecarei echipe
long long S[NMAX+1];                        // sume partiale pentru puterile tuturor candidatilor unei echipe
long long Sim ( int i, int p, int &j ) {    // echipa i, primul jucator, ultimul jucator
  int N = n[i];                             // lungimea listei curente
  long long sum = S[N-1];                   // suma tuturor puterilor din echipa i, e ultimul elem din vect de sume partiale
  long long moves = L / sum * N;            // L / s[i] - de cate ori a mutat toata echipa * N de membrii ai echipei
  long long rest = L - ( L / sum ) * sum;   // cate casute mai am de sarit
  if ( rest == 0 )                          // daca nu mai am casute de sarit
    j = ( p + N - 1 ) % N;                  // jucatorul care termina jocul este ultimul din lista circulara ce incepe la pozitia p
  else{                                     // cautam secvential restul in vectorul de sume partiale
    j = 0;
    while ( S[j] < rest ) {                 // cautam secvential restul pe vectorul de sume partiale
      moves ++; j++;                        // si contorizam n de mutari
    }
    moves++;
    j = ( j + p ) % N;                      // pozitia jucatorului care va muta ultimul
  }
  return moves;                             // n de mutari necesar echipei i pentru a termina traseul
}
int main(){
  int cer, K, ecuson, P,N;
  int M = 0;                            // n de echipe participante
  int maxj = 0;                         // n maxim de jucatori dintr-o echipa
  int Hazard;                           // codul-ul echipei Hazard, echipa cu cei mai multi participanti
  fin >> cer >> N >> L >> K;            // cer - cerinta, L - lungimea traseului, K numarul rundei de analizat
  while ( fin >> ecuson >> P ){         // citim datele jucatorilor si ii repartizam pe echipe
    int i = ecuson % 100;               // codul planetei
    if ( n[i] == 0 )                    // daca echipa i e vida
      M ++;                             // mai am o echipa in plus
    E[i][n[i]].cp = ecuson / 100;       // adaug in echipa planetei i codul jucatorului
    E[i][n[i]].pw = P;                  // si puterea acestuia
    n[i]++;                             // creste numarul membrilor echipe planetei i
    if ( n[i] > maxj ){                 // determinam codul planetei Hazard
      maxj = n[i];                      // n maxim de membrii dintr-o echipa
      Hazard = i;                       // codul planetei Hazard
    }
  }
  if ( cer == 1 )
    fout << M << " " << Hazard;                   // n de echipe, codul planetei Hazard
  else if ( cer == 2 ){
    int min_moves = LM + 1;                       // min de mutari facute de o echipa, initializam cu maximul de mutari posibile
    int winer_team, winer_player;                 // n echipei care termina prima jocul k, jucatorul din echipa castigatoare care muta ultimul
    for ( int i = 1; i <= MMAX; i ++ ){           // pt fiecare echipa
      int nr = n[i];                               // extragem n de membrii ai echipei i
      if ( nr ) {                                  // daca n de membrii ai echipei e nenul,
        int p = ( K - 1 ) % nr;                    // determinam pozitia jucatorului care va muta primul din echipa planetei i
        S[0] = E[i][p].pw;                        // sume partiale pentru puterile echipei planetei i, incepand cu pozitia p
        for ( int j = 1; j < nr; j ++ )            // sume partiale incepand cu pozitia p
          S[j] = S[j-1] + E[i][(j+p)%nr].pw;
        int j;                                    // variabila in care transmit jucatorul care va finaliza cursa
        int moves = Sim( i, p, j );               // n de mutari pana la start al echipei planetei i daca ar incepe cu jucatorul p; finalizeaza jucatorul j
        if ( moves < min_moves ){                 // retin n minim de mutari, echipa castigatoare si numele jucatorului care finalizeaza cursa
          min_moves = moves;                      // N minim de mutari
          winer_team = i;                         // n de ordine al echipei care termina jocul
          winer_player = E[i][j].cp;              // numele jucatorului care termina jocul
        }
      }
    }
    fout << winer_team << " " << winer_player;
  }
  return 0;
}