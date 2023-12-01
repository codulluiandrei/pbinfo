#include <iostream>
#include <math.h>
using namespace std;
long long n, m, i, delta, q, r ;

int main()
{
    cin >> n >> m ;
    i = 2 ;
    while( n % i != 0 ) i++ ;
    cout << i << " " ;
    n = n / i ;
    m = m / (i-1) ;
    delta = ( n - m + 1 ) * ( n - m + 1 ) - 4 * n ;
    q = (( n - m + 1 ) - (long long)sqrt(delta)) / 2 ;
    r = (( n - m + 1 ) + (long long)sqrt(delta)) / 2 ;
    cout << q << " " << r ;
    return 0;
}
