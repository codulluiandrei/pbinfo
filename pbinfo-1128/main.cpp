#include <iostream>
using namespace std;
long long m , n , q , i ;
int main()
{
    cin >> m >> n ;
    if ( m > n ) cout << 0 ;
    else
       {
           q = 1 ;
           for ( i = n - m + 1 ; i <= n ; i++ ) q = ( q * i) % 224737 ;
           cout << q ;
       }
    return 0;
}