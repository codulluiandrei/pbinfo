#include <iostream>

using namespace std;

long long n,b,r,k,x,s,i,nr ;

int main()
{
    cin >> n >> b >> r ;
    // numarul cifrelor lui r
    k = 0 ;
    x = r ;
    while ( x != 0 )
    {
        k++ ;
        x = x / 10 ;
    }
    // afisare
    if ( k > n ) cout << -1 ;
    else if ( k == n ) cout << r ;
         else
           {
              s = 1 ;
              for ( i = 2 ; i <= n ; i++ ) s = ( s * 10 ) % b ;
              if ( s <= r ) nr = r - s ;
              else nr = b - s + r ;
              if ( nr == 0 )
              {
                  cout << 1 ;
                  for ( i=1 ; i<=n-1 ; i++ ) cout << 0 ;

              }
              else
              {
              k = 0 ;
              x = nr ;
              while ( x != 0 )
               {
                 k++ ;
                 x = x / 10 ;
               }
              cout << 1 ;
              for ( i=1 ; i<=n-k-1 ; i++ ) cout << 0 ;
              cout << nr ;
              }
           }
    return 0;
}
