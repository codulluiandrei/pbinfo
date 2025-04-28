#include <fstream>
using namespace std ;
ifstream f ("produs_matrice.in") ;
ofstream g ("produs_matrice.out") ;
int A[105][105] , B[105][105] ;
long long C[105][105] ;
int main ()
{
 //citim
 int m , n , p ;
 f >> m >> n ;
 for ( int i = 1 ; i <= m ; ++i )
    for ( int j = 1 ; j <= n ; ++j )
        f >> A[i][j] ;
 f >> p ;
 for ( int i = 1 ; i <= n ; ++i )
    for ( int j = 1 ; j <= p ; ++j )
        f >> B[i][j] ;
 //calculam produsul
 for ( int i = 1 ; i <= m ; ++i )
    for ( int j = 1 ; j <= p ; ++j )
        for ( int k = 1 ; k <= n ; ++k )
            C[i][j] = C[i][j] + A[i][k] * B[k][j] ;
 //afisam
 for ( int i = 1 ; i <= m ; ++i )
    {
     for ( int j = 1 ; j <= p ; ++j )
        g << C[i][j] << " " ;
     g << "\n" ;
    }
}