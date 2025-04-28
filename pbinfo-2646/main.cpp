#include <iostream>
using namespace std;
int m, n, i, minim, a[21], viz[21] ;
void backtrack( int niv, int suma )
{
    int mini, b, c, j, i ;
    if( niv == m )
    {
        i = m ;
        while( viz[i] != 0 ) i++ ;
        b = a[i] ;
        viz[i] = 1 ;
        j = i ;
        while( viz[j] != 0 ) j++ ;
        c = a[j] ;
        mini = b % c ;
        if( c % b < mini ) mini = c % b ;
        if( suma + mini < minim ) minim = suma + mini ;
        viz[i] = 0 ;
    }
    else
    {
        i = niv ;
        while( viz[i] != 0 ) i++ ;
        b = a[i] ;
        viz[i] = 1 ;
        for( j = i + 1 ; j <= n ; j++ )
            if( viz[j] == 0 )
        {
            c = a[j] ;
            viz[j] = 1 ;
            mini = b % c ;
            if( c % b < mini ) mini = c % b ;
            backtrack( niv + 1 , suma + mini ) ;
            viz[j] = 0 ;
        }
        viz[i] = 0 ;
    }
}
int main()
{
    cin >> n ;
    for( i = 1 ; i <= n ; i++ )
        cin >> a[i] ;
    m = n / 2 ;
    minim = 1000000 ;
    backtrack(1,0) ;
    cout << minim ;
    return 0;
}