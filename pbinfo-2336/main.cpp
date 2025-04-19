#include <fstream>
#define dim 50000002
using namespace std;
ifstream f("primcolor.in");
ofstream g("primcolor.out");
char v[dim];
int n,m,i,j,nr,k ;
int main()
{
    f >> n ;
    if ( n<=3 ) g << n ;
    else
    {
        m = n / 2 ;
        v[3] = 0 ;
        for ( i=3 ; i<=m ; i=i+2 )
            if ( v[i]==0 )
        {
            k = i + i ;
            j = i + k ;
            while ( j<=n )
            {
                v[j] = 1 ;
                j = j + k ;
            }
        }
        if ( m%2==1 ) m++ ;
        nr = 2 ;
        for ( i=m+1 ; i<=n ; i=i+2 )
            if ( v[i]==0 )
        {
            nr++ ;
            k = i + i ;
            j = i + k ;
            while ( j<=n )
            {
                v[j] = 1 ;
                j = j + k ;
            }
        }
        g << nr ;
    }
    return 0;
}