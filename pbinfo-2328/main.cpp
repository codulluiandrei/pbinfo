#include <fstream>
#define m 10000000

using namespace std;
ifstream f("prim013.in");
ofstream g("prim013.out");
long long n,i,j,e,nr,x,p[30];
char v[m+1] ;

int main()
{
    p[1] = 1 ;
    p[2] = 0 ;
    for( i=2 ; i<=25 ; i++ )
        if ( p[i]==0)
        {
            j = i+i ;
            while ( j<=25 )
            {
                p[j] = 1 ;
                j = j+i ;
            }
        }
    //ciurul lui Eratostene
    v[1] = 1 ;
    v[2] = 0 ;
    for ( i=2 ; i<=m ; i++ )
        if( v[i]==0 )
        {
            j = i+i ;
            while ( j<=m )
            {
                v[j] = 1 ;
                j = j+i ;
            }
            //bifez puterile lui i-prim care au exponentul=nr.prim-1 , cu 2
            if ( i<=3162 )
            {
               j = i*i ;
               e = 2 ;
               while( j<=m )
               {
                   if ( p[e+1]==0 ) v[j] = 2 ;
                   j = j*i ;
                   e++ ;
               }
            }

        }
    nr = 0 ;
    f >> n ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        if ( v[x]!=1 ) nr++ ;
    }
    g << nr ;
    return 0;
}
