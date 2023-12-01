#include <iostream>

using namespace std;
long long n,m,nr,e,i ;

int main()
{
    cin >> n ;
    m = n ;
    nr = 1 ;
    e = 0 ;
    while ( n%2==0)
    {
       e++ ;
       n = n / 2 ;
    }
    nr = ( nr * ( e * m + 1 ) ) % 59999 ;
    for( i=3 ; i*i<=n ; i = i + 2 )
        if ( n % i == 0 )
        {
            e = 0 ;
            while ( n % i == 0 )
            {
                e++ ;
                n = n / i ;
            }
            nr = ( nr * ( e * m + 1 ) ) % 59999 ;
        }
     if ( n > 1 )  nr = ( nr * ( m + 1 ) ) % 59999 ;
     cout << nr ;
    return 0;
}
