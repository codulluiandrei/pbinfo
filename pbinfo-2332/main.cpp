#include <fstream>

using namespace std;
ifstream f("primxxl.in");
ofstream g("primxxl.out");
long long n,k,i,j,m,x,prod,nr,ok,ep,v[32002],p[3500],e[3500] ;

int main()
{
    f >> n >> k ;
    // numerele prime pana la 32000 si exponentii lor in k!
    v[2]=0 ;
    for(i=2 ; i<=32000 ; i++)
        if(v[i]==0)
    {
        m++ ;
        p[m] = i ;
        e[m] = 0 ;
        prod = i ;
        while ( prod<=k )
        {
            e[m] += k/prod ;
            prod = prod*i ;
        }
        j = i+i ;
        while ( j<=32000 )
        {
            v[j] = 1 ;
            j = j+i ;
        }
    }
    nr = 0 ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        if( x<=k ) nr++ ;
        else
        {
        j = 1 ;
        ok = 1 ;
        while (( p[j]*p[j]<=x )and(ok==1))
        {
            ep = 0 ;
            while( x%p[j]==0 )
            {
                ep++ ;
                x = x/p[j] ;
            }
            if( ep>e[j] ) ok=0 ;
            j++ ;
        }
        if ( x>k ) ok=0 ;
        if( ok==1 ) nr++ ;
        }
    }
    g << nr ;

    return 0;
}
