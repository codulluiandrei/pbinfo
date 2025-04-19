#include <fstream>
using namespace std;
ifstream f("prim023.in");
ofstream g("prim023.out");
int n,i,j,k,p,u,x,ok,t,v[32001],prim[3500] ;
int main()
{
    f >> n ;
    v[1] = 1 ;
    v[2] = 0 ;
    k = 0 ;
    for ( i=2 ; i<=32000 ; i++ )
        if ( v[i]==0 )
    {
        k++ ;
        prim[k] = i ;
        j = i+i ;
        while ( j<=32000 )
        {
            v[j] = 1 ;
            j = j+i ;
        }
    }
    u = 0 ;
    p = 0 ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        if ( x==1 ) u++ ;
        else
        {
            ok = 1 ;
            j = 1 ;
            while (( prim[j]*prim[j]<=x )and( ok==1 ))
                if ( x%prim[j]==0 ) ok = 0 ;
                else j++ ;
            if ( ok==1 ) p++ ;
        }
    }
    if ( p==0 ) g << 0 ;
    else if ( u==0 ) g << p ;
         else
         {
             v[1] = p ;
             k = 1 ;
             for( i=1 ; i<=u ; i++ )
             {
                 t = 0 ;
                 for( j=1 ; j<=k ; j++ )
                 {
                     x = ( v[j]*2+t )%10 ;
                     t = ( v[j]*2+t)/10 ;
                     v[j] = x ;
                 }
                 while ( t>0 )
                 {
                     k++ ;
                     v[k] = t%10 ;
                     t = t/10 ;
                 }
             }
             for ( i=k ; i>=1 ; i-- )
                g << v[i] ;
         }
    return 0;
}