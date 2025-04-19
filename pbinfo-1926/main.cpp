#include <fstream>
using namespace std;
ifstream f("numarspecial.in");
ofstream g("numarspecial.out");
long long n , i , j , minim , maxim , a , b , p , q , x ;
int v[1000002] ;
int main()
{
    f >> n ;
    a = 0 ;
    b = 0 ;
    maxim = 0 ;
    // eratostene
    v[1] = 1 ;
    for( i=2 ; i<=1000000 ; i++ )
      if ( v[i]==0 )
      {
          j = i * i ;
          while ( j<=1000000 )
          {
              v[j] = 1 ;
              j = j + i ;
          }
      }
     //prelucrare sir
     q = 0 ;
     for ( i=1 ; i<=n ; i++ )
     {
         f >> x ;
         if ( v[x]==0 ) q++ ;
         else
         {
            if (( p>0 ) and ( q>0 )) b++ ;
            if ( p>q ) minim = q ;
            else minim = p ;
            if ( minim>maxim ) maxim = minim ;
            if ( x%9==0 ) { a++ ; p=q ; q=0 ; }
            else { p=0 ; q=0 ; }
         }
     }
     if ( v[x]==0 )
     {
        if (( p>0 ) and ( q>0 )) b++ ;
        if ( p>q ) minim = q ;
        else minim = p ;
        if ( minim>maxim ) maxim = minim ;
     }
     g << a << "\n" << b <<"\n" << maxim ;
    return 0;
}