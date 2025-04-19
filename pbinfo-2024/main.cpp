#include <fstream>
using namespace std;
ifstream f("divizor112.in");
ofstream h("divizor112.out");
int n,ma,i,j,x,y,a[1000001],viz[1000001],v[1000001][8];
int main()
{
    f >> n ;
    ma=0 ;
    a[1]=1 ;
    for( i=2 ; i<1000000 ; i++ )
       if ( a[i]==0 )
       {
           j=i+i ;
           while ( j<1000000 )
           {
               v[j][0]++ ;
               v[j][v[j][0]]=i ;
               a[j]=1 ;
               j=j+i ;
           }
       }
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        if ( a[x]==0 ) viz[x]++ ;
        else for ( j=1 ; j<=v[x][0] ; j++ ) viz[v[x][j]]++ ;
    }
    for(i=2 ; i<1000000 ; i++)
       if(viz[i]>ma) {ma=viz[i] ; y=i ;}
    h << y ;
    return 0;
}