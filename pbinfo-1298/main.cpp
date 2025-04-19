#include <iostream>
using namespace std;
long n , m , i , s , j , a[100000] , t , x ;
int main()
{
    cin >> n ;
    a[1] = 1 ;
    m = 1 ;
    for ( i = 1 ; i <= n ; i++ )
      {
        t = 0 ;
        for ( j = 1 ; j <= m ; j++ )
          {
              x = a[j] ;
              a[j] = ( a[j] * 2 + t ) % 10000 ;
              t = ( x * 2 + t ) / 10000 ;
          }
        if ( t > 0 ) { m++ ; a[m] = t ;}
      }
     s = 0 ;
     for ( i = 1 ; i <= m ; i++ )
     {
         x = a[i] ;
         while ( x != 0)
          {
              s = s + x % 10 ;
              x = x / 10 ;
          }
     }
     cout << s ;
    return 0;
}