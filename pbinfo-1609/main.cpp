#include <fstream>
using namespace std;
ifstream f("paralele.in");
ofstream g("paralele.out");
long a[1001] , v[2000001] , n , i , j , x , maxim ;
int main()
{
    f >> n ;
    maxim = 0 ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> a[i] ;
        for ( j=1 ; j<i ; j++ )
        {
            if( a[i]>a[j] ) x = a[i]-a[j];
                       else x = a[j]-a[i];
            v [x]++ ;
            if ( v[x] > maxim ) maxim = v[x] ;
        }
    }
    g << maxim ;
    return 0;
}