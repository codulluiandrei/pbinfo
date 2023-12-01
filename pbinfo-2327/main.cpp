#include <fstream>
#define m 10000000

using namespace std;
ifstream f("prim997.in");
ofstream g("prim997.out");
int n,lmax,lung,pozc,i,j,k,pmax,lm[m+1],p[m+1] ;
char v[m+1] ;

int main()
{
    f >> n ;
    v[1] = 1 ;
    p[1] = 1 ;
    lm[1] = 1 ;
    v[2] = 0 ;
    lmax = 1 ;
    pmax = 1 ;
    lung = 0 ;
    for ( i=2 ; i<=m ; i++ )
        if( v[i]==0 )
        {
            lm[i] = lmax ;
            p[i] = pmax ;
            j = i+i ;
            while ( j<=m )
            {
                v[j] = 1 ;
                j = j+i ;
            }
            lung = 0 ;
        }
        else
        {
           lung++ ;
           if ( v[i-1]==0 ) pozc = i ;
           if ( lung > lmax ) { lmax = lung ; pmax = pozc ; }
           lm[i] = lmax ;
           p[i] = pmax ;
        }
    for ( i=1 ; i<=n ; i++)
    {
        f >> k ;
        g << p[k] << " " << lm[k] << "\n" ;
    }

    return 0;
}
