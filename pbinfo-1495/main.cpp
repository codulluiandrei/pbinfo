#include <fstream>
using namespace std;
ifstream f("memory004.in");
ofstream g("memory004.out");
long i , m , n , j , suma , maxim , x ;
short int s[1002] , lung[1002] , t[1002] ;
char v[10001], p[1002] ;
int main()
{
    v[1]=1 ;
    for ( i=2 ; i<10000 ; i++ )
      if ( v[i]==0 )
        {
            for ( j=i*i ; j<10000 ; j=j+i ) v[j]=1 ;
        }
    f >> m >> n ;
    for ( i=1 ; i<=m ; i++ )
      for ( j=1 ; j<=n ; j++ )
        {
            f >> x ;
            if ( v[x]==0 ) lung[j]++ ;
                      else {
                              if ( p[j]==0 ) { s[j]=lung[j] ; p[j]=1 ; }
                              if ( lung[j]>maxim ) maxim=lung[j] ;
                              lung[j]=0 ;
                           }
            if (( i==m ) && ( v[x]==0 )) t[j]=lung[j] ;
                                    else t[j]=0 ;
        }
    for ( j=1 ; j<=n ; j++ )
      {
        if ( lung[j]>maxim ) maxim=lung[j];
        if ( lung[j]==m ) s[j]=m ;
      }
    suma=t[1] ;
    for ( j=2 ; j<=n+1 ; j++ )
      if ( s[j]==m ) suma=suma+m ;
               else {
                      suma=suma+s[j];
                      if( suma>maxim ) maxim=suma ;
                      suma=t[j] ;
                    }
    g << maxim ;
    return 0;
}