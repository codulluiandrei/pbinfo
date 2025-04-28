#include <iostream>
using namespace std;
int n , k , p , c , u ;
int main()
{
    cin >> n ;
    k = 0 ;
    p = 1 ;
    c = 0 ;
    while ( n != 0 )
    {
        c++ ;
        p = p * c ;
        u = n % 10 ;
        if ( u % 2 == 0 ) k++ ;
        n = n / 10 ;
    }
    p = ( p / c ) * k ;
    cout << p ;
    return 0;
}