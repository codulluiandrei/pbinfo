#include <fstream>
#define a 999999999

using namespace std;
ifstream f("numar9.in");
ofstream g("numar9.out");

long long s , k , i , r , c , x , m , n ;

int main()
{
    f >> s >> k ;
    r = s % 9 ;
    c = s / 9 ;
    m = c / 9 ;
    n = c % 9 ;
    if ( r != 0 ) g << r ;
    x = r % k ;
    for ( i = 1 ; i <= n ; i++ )
    {
         g << 9 ;
         x = ( x * 10 + 9 ) % k ;
    }
    for ( i = 1 ; i <= m ; i++ )
    {
         g << a ;
         x = ( x * 1000000000 + a ) % k ;
    }
    g << "\n" ;
    g << x ;

    return 0;
}
