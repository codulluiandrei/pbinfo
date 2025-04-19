#include <fstream>
#include <cstring>
#include <list>
using namespace std;
ifstream fin("retea.in");
ofstream fout("retea.out");
int use[101],n,m,k,v[101][101],i,x,y;
list < int > G[101];
void DF( int nod, int srv )
{
    ++k;
    use[ nod ] = 1;
    for( auto it : G[ nod ] )
        if( !use[ it ] && it != srv )
            DF( it , srv );
}
int main()
{
    fin>>n>>m;
    for( i = 1 ; i <= m ; i++ )
    {
        fin>>x>>y;
        G[ x ].push_back( y );
        G[ y ].push_back( x );
    }
    for( i = 1 ; i <= n ; i++ )
    {
        k = 0;
        memset( use , 0 , sizeof( use ) );
        if( i == 1 )
        {
            DF( 2 , 1 );
            if( k == n- 1 )
                fout<<0<<' ';
            else
                fout<<1<<' ';
        }
        else
        {
            DF( 1 , i );
            if( k == n- 1 )
                fout<<0<<' ';
            else
                fout<<1<<' ';
        }
    }
return 0;
}