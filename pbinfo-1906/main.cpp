#include <fstream>
#include <bitset>

using namespace std;

ifstream f("memory007.in");
ofstream g("memory007.out");

bitset<700020> v ;
long n , m , a , b , i , j , nr , x ;
long long suma , r , t ;

int main()
{
    f >> n >> m >> a >> b ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        j = x-a ;
        v[j] = 1 ;
    }
    j = 0 ;
    nr = 0 ;
    suma = 0 ;
    for ( i=1 ; i<=m ; i++)
    {
        f >> x ;
        while ( nr < x )
        {
          nr = nr + v[j] ;
          j++ ;
        }
        suma = suma + j - 1 ;
    }
    r = m ;
    t = a ;
    suma = suma + r * t ;
    g << suma ;
    return 0;
}
