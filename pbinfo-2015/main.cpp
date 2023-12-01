#include <fstream>

using namespace std;
ifstream f("sumagauss1.in");
ofstream g("sumagauss1.out");
long long a,b,c,d,n,i,t,q,v[1000],k;

void produs(long long x)
{
    t = 0 ;
    for ( i=1 ; i<=k ; i++ )
    {
        q = v[i] * x + t ;
        v[i] = q % 10 ;
        t = q / 10 ;
    }
    while ( t!=0 )
    {
        k++ ;
        v[k] = t % 10 ;
        t = t / 10 ;
    }
}

int main()
{
    f >> n ;
    a = n ;
    b = n+1 ;
    c = n+2 ;
    d = 3*n*n+6*n+1 ;
    if ( a%2==0 ) a = a / 2 ;
    else b = b / 2 ;
    if ( c%2==0 ) c = c / 2 ;
    else d = d / 2 ;
    if ( a%3==0 ) a = a / 3 ;
    else if ( b%3==0 ) b = b / 3 ;
         else c = c / 3 ;
    if ( a%5==0 ) a = a / 5 ;
    else if ( b%5==0 ) b = b / 5 ;
         else if ( c%5==0 ) c = c / 5 ;
              else d = d / 5 ;
    v[1] = 1 ;
    k = 1 ;
    produs(a) ;
    produs(b) ;
    produs(c) ;
    produs(d) ;
    for ( i=k ; i>=1 ; i-- ) g << v[i] ;
    return 0;
}
