#include <iostream>

using namespace std;

long long n,i,j,k,p[21000],prim[3000],v[21000],x,nr,nr1;

int main()
{
    cin >> n ;
    p[1] = 1 ;
    p[2] = 0 ;
    for ( i=2 ; i<=20000 ; i++ )
        if ( p[i]==0 )
    {
        k++ ;
        prim[k] = i ;
        j = i+i ;
        while (j<=20000)
        {
            p[j] = 1 ;
            j = j+i ;
        }
    }
    for ( i=1 ; i<=n ; i++)
    {
        cin >> x ;
        v[x]++ ;
    }
    nr = 0 ;
    for ( i=2 ; i<=k ; i++ )
        for ( j=1 ; j<=prim[i] ; j=j+2 )
            nr = nr+v[j]*v[prim[i]-j] ;
    if (v[1]>1) nr = nr+v[1]*(v[1]-1)/2 ;
    nr = nr+v[0]*v[2] ;
    cout << nr ;
    return 0;
}
