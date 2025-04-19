#include <fstream>
using namespace std;
ifstream f("produs2.in");
ofstream g("produs2.out");
long long i , n , p , nr , prod , j , a[1000002] ;
int main()
{
    f >> n >> p ;
    for ( i = 1 ; i <= n ; i++ ) f >> a[i] ;
    nr = 0 ;
    i = 1 ;
    j = 0 ;
    prod = 1 ;
    while ( j < n )
    {
        j++ ;
        prod = prod * a[j] ;
        if ( prod < p ) nr = nr + j - i + 1 ;
        else {
               while ( prod >= p ) { prod = prod / a[i] ; i++ ; }
               nr=nr+j-i+1;
             }
    }
    g << nr ;
    return 0;
}