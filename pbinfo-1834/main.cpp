#include <fstream>
using namespace std;
ifstream f("memory005.in");
ofstream g("memory005.out");
long long n , i , j , p , x , m , a[30] ;
int main()
{
    f >> n ;
    // verific daca multimea are un element impar
    f >> x ;
    i = 1 ;
    while ( (i<n) and (x%2==0) ) { f >> x ; i++ ; }
    m = n - x%2 ;
    // trec m in baza 2 pentru a calcula 2^m in timp logaritmic
    j = 0 ;
    while ( m!=0 )
    {
       j++ ;
       a[j] = m%2 ;
       m = m/2 ;
    }
    // calculez 2^m in timp logaritmic
    p = 1 ;
    for ( i=j ; i>=1 ; i--)
    {
        if ( a[i]==1 ) p =( p * p * 2 ) % 666013 ;
                  else p = ( p * p ) % 666013 ;
    }
    p = ( p -1 ) % 666013 ;
    g << p ;
    return 0;
}