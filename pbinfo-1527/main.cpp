#include <fstream>
using namespace std;
ifstream f("zoom.in");
ofstream g("zoom.out");
short int a[1001][1001];
long long put[11] , val[1001], va[11] , x ;
long p , m , n , i , j , nr , ok , k ;
int main()
{
    f >> p >> m >> n ;
    put[0]=1 ;
    for ( i=1 ; i<=p ; i++ ) put[i]=put[i-1]*3 ;
    for ( i=1 ; i<=p ; i++ )
       for ( j=1 ; j<=p ; j++ )
        {
            f >> x ;
            va[j] += x*put[i-1] ;
        }
    for( i=1 ; i<=p-1 ; i++ )
    {
        for( j=1; j<=n ; j++ )
        {
            f >> a[i][j] ;
            val[j] += a[i][j]*put[i-1] ;
        }
    }
    for( j=1 ; j<p ; j++ )
    {
       f >> a[p][j] ;
       val[j] += a[p][j]*put[p-1] ;
    }
    for( j=p ; j<=n ; j++ )
    {
       f >> a[p][j] ;
       val[j] += a[p][j]*put[p-1] ;
       ok=1 ;
       for ( k=p ; k>=1 ; k-- )
         if ( va[k]!=val[j+k-p]){ ok=0 ; break ; }
       nr +=ok ;
    }
    for ( i=p+1 ; i<=m ; i++ )
    {
       for( j=1 ; j<p ; j++ )
       {
          f >> a[i][j] ;
          val[j] = ( val[j]-a[i-p][j])/3+a[i][j]*put[p-1] ;
       }
       for( j=p ; j<=n ; j++ )
       {
          f >> a[i][j] ;
          val[j] = ( val[j]-a[i-p][j])/3+a[i][j]*put[p-1] ;
          ok=1 ;
          for ( k=p ; k>=1 ; k-- )
            if ( va[k]!=val[j+k-p]){ ok=0 ; break ; }
          nr +=ok ;
       }
    }
    g << nr ;
    return 0;
}