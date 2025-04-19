#include <fstream>
#include <bitset>
using namespace std;
ifstream f("douamii17.in");
ofstream g("douamii17.out");
#define k 500000000
long n , i , nr , b[20001] , p[2020] , x ;
long long j ;
bitset<500000001> a ;
int main()
{   // aflu primele 2017 numere prime
    nr = 0 ;
    i = 2 ;
    while ( nr < 2017 )
    {
       if ( b[i] == 0 )
       {
          nr++ ;
          p[nr] = i ;
          j = i * i ;
          while ( j < 20000 )
          {
              b[j] = 1 ;
              j = j + i ;
          }
       }
       i++ ;
    }
    // marchez divizorii celor 2017 numere
    a[1] = 1 ;
    for ( i = 1 ; i <= 2017  ; i++ )
    {
        j = p[i] ;
        while ( j < k )
        {
            a[j] = 1 ;
            j = j * p[i] ;
        }
    }
    // verificarea
    f >> n ;
    for ( i = 1 ; i <= n ; i++ )
    {
        f >> x ;
        g << a[x] << "\n" ;
    }
    return 0;
}