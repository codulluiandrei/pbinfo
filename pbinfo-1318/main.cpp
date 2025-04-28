#include <fstream>
#include <iostream>
using namespace std ;
ifstream f ("bipartit1mare.in") ;
ofstream g ("bipartit1mare.out") ;
int n , m , a[102][102] , x[102] , gasit ;
void citire() ;
void back ( int ) ;
void verif () ;
bool valid ( int k ) ;
void afisare () ;
int main ()
{
 citire() ;
 back ( 1 ) ;
 if ( !gasit )
    g << "NU" ;
 return 0 ;
}
void citire()
{
 f >> n >> m ;
 for ( ; m ; --m )
    {
     int i , j ;
     f >> i >> j ;
     a[i][j] = a[j][i] = 1 ;
    }
}
void back ( int k )
{
 for ( int i = 1 ; i <= 2 && !gasit ; ++i )
    {
     x[k] = i ;
     if ( valid ( k ) )
        if ( k == n )
            afisare() ;
        else
            back ( k + 1 ) ;
    }
}
bool valid ( int k )
{
 for ( int i = 1 ; i < k ; ++i )
    if ( x[i] == x[k] && a[i][k] == 1 )
        return false ;
 return true ;
}
void afisare ()
{
 gasit = true ;
 g << "DA\n" ;
 for ( int cnt = 1 ; cnt <= n ; ++cnt )
    if ( x[cnt] == 1 )
        g << cnt << " " ;
 g << "\n" ;
 for ( int cnt = 1 ; cnt <= n ; ++cnt )
    if ( x[cnt] == 2 )
        g << cnt << " " ;
}