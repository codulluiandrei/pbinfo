#include <fstream>
using namespace std;
ifstream f("summit.in");
ofstream g("summit.out");
long long n , i, k , mij , x , s[1000001];
long long caut(long long st , long long dr)
{
    if ( st > dr ) return 0 ;
    else
     {
        mij = ( st + dr ) / 2 ;
        if ( s[mij] == x ) return mij ;
        else
         {
            if ( x < s[mij] ) caut(st,mij-1) ;
            else caut(mij+1,dr) ;
         }
     }
}
int main()
{
    f >> n ;
    f >> x ;
    s[1] = x ;
    g << 1 << "\n" ;
    for ( i=2 ; i<=n ; i++ )
    {
        f >> x ;
        s[i] = s[i-1] + x ;
        k = caut(1,i-1) ;
        g << k << "\n" ;
    }
    return 0;
}