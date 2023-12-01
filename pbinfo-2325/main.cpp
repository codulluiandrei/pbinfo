#include <iostream>

using namespace std;

int i,k,t,a,b,j,u,p[500011],pr[50000],v[1000001],c[1000001] ;

int main()
{
    p[1] = 1 ;
    p[2] = 0 ;
    k = 0 ;

    for ( i=2 ; i<=500010 ; i++ )
        if ( p[i]==0 )
        {
           k++ ;
           pr[k] = i ;
           j = i+i ;
           while( j<=500010 )
           {
               p[j] = 1 ;
               j = j+i ;
           }
        }
     for( i=1 ; i<=170 ; i++ )
     {
        j=i ;
        u=pr[i]*pr[j] ;
        while( u<=1000000)
        {
            v[u]=1 ;
            j++ ;
            u=pr[i]*pr[j] ;
        }
     };
     c[0]=0 ;
     v[2]=0 ;
     for( i=1 ; i<=1000000 ; i++ )
        if ( v[i]==1 )c[i] = c[i-1]+1 ;
        else c[i] = c[i-1] ;
     cin >> t ;
     for ( i=1 ; i<=t ; i++)
     {
         cin >> a >> b ;
         cout << c[b]-c[a-1] << " " ;
     }
    return 0;
}
