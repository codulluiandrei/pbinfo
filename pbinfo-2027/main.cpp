#include <fstream>
using namespace std;
ifstream f("roadtooni.in");
ofstream g("roadtooni.out");
int n,i,j,k,x,v[21][2020] ;
int main()
{
    f >> n ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> k ;
        for ( j=1 ; j<=k ; j++ )
        {
            f >> x ;
            v[i][x]=1 ;
        }
        for ( j=1 ; j<=1000 ; j++ )
           if (( v[i][j]==0 ) and ( v[i][2017-j]==0 ))
             {
                 g << 2 << " " << j << " " << 2017-j << "\n" ;
                 break ;
             }
    }
    return 0;
}