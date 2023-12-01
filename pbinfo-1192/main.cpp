/*
Aceasta problema se bazeaza pe un algoritm de sortare numit Counting Sort ( algoritm de numarare )
Solutii alternative :
- algoritm de sortare de complexitate O ( N * N ) - 40p
- algoritm de sortare rapida prin comparare O ( N * log N ) - 80p
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std ;

ifstream fin ("arhitectura2.in") ;
ofstream fout ("arhitectura2.out") ;

int n ;
int a[2000005] ; //memoreaza inaltimile
int b[2000005] ; //memoreaza inaltimile sortate
int c[2000005] ; //memoreaza frecvente

int main ()
{
 //citim
 fin >> n ;
 int inaltime_maxima = 0 ;
 for ( int i = 0 ; i < n ; ++i )
    {
     fin >> a[i] ;
     if ( a[i] > inaltime_maxima )
        inaltime_maxima = a[i] ;
    }

 //sortarea prin numarare
 int k = inaltime_maxima ;

 for ( int i = 0 ; i < n ; ++i )
    c[a[i]]++ ;
 for (int i = 1 ; i < k + 1 ;  ++i )
    c[i] += c[i-1] ;
 for (int i = n - 1 ; i >= 0 ; --i )
     b[--c[a[i]]] = a[i] ;

 //raspundem la problema
 for ( int i = n - 1 ; i >= 0 ; --i )
    fout << b[i] << " " ;
 fout << "\n" ;

 for ( int i = n - 1 ; i > 0 ; --i )
    {
     if ( b[i] * 2 == b[i-1] + b[i+1] )
        fout << "1 " ;
     else
        fout << "0 " ;
    }
 if ( b[1] == 2 * b[0] )
    fout << "1" ;
 else
    fout << "0" ;

}

