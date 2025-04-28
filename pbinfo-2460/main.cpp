#include <fstream>
#include <cstring>
#include <cassert>
using namespace std;
ifstream fin( "multimi5.in" );
ofstream fout( "multimi5.out" );
int i,j,n,m,k,a,bitmask[ (1<<16) ],s[20],f[20],r[20],ev[300],st[10010],val[300],norm[300],ans[16 * 10010],ok,mini,bmsk;
char tr,multimea,exp[1010],evexp[1019];
int valori[ 20 ];
int INDEX = 0;
char top()
{
    return evexp[ INDEX ];
}
char pop()
{
    return evexp[ INDEX ++ ];
}
int solveR();
int solveP()
{
    if( top() != '(' )
        return pop()-'0';
    else if( top() == '(' )
    {
        pop();
        int rez = solveR();
        pop();
        return rez;
    }
return 0;
}
int solveI()
{
    int rez = solveP();
    while( top() == '*' )
    {
        pop();
        rez = min( rez , solveP() );
    }
    return rez;
}
int solveR()
{
    int rez = solveI();
    while( top() == '+' )
    {
        pop();
        rez = max( rez , solveI() );
    }
    return rez;
}
int main()
{
    fin>>n;
    assert( n <= 16 );
    fin.get();
    for( int i = 1 ; i <= n ; i++ )
    {
        fin>>multimea>>tr>>valori[i]>>tr>>f[i]>>tr>>r[i];
        norm[ multimea ] = 'A' + i - 1;
        ev[ multimea ] = i;
        assert( f[ i ] <= 1000000000 );
    }
    fin.get();
    fin.get( exp , 10005 );
    k = strlen( exp );
    assert( k >= 3 );
    assert( k <= 1000 );
    for( int i = 0 ; i < k ; i++ )
    {
        if( exp[ i ] >= 'A' && exp[ i ] <= 'Z' )
            exp[ i ] = norm[ exp[ i ] ];
    }
    val[ '+' ] = '+';
    val[ '*' ] = '*';
    val[ '(' ] = '(';
    val[ ')' ] = ')';
    for( int i = 0 ; i < ( 1<<(n) ) ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            val[ 'A' + j ] = '1';
            if( ( i & (1<<(j)) ) == 0 )
                val[ 'A' + j ] = '0';
        }
        for( int j = 0 ; j < k ; j++ )
            evexp[ j ] = val[ exp[ j ] ];
        INDEX = 0;
        bitmask[ i ] = solveR();
    }
    ok = 1;
    while( ok == 1 )
    {
        ok = 0;
        mini = 1000000009;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( valori[ i ] <= f[ i ] )
            {
                ok = 1;
                mini = min( mini , valori[ i ] );
            }
        }
        bmsk = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( valori[ i ] == mini && valori[ i ] <= f[ i ] )
            {
                bmsk += ( 1 <<(i-1) );
                valori[ i ] += r[ i ];
            }
        }
        if( bitmask[ bmsk ] == 1 )
        {
            ans[ ++ans[ 0 ] ] = mini;
        }
    }
    fout<<ans[ 0 ]<<'\n';
    for( int i = 1 ; i <= ans[ 0 ] ; i++ )
    {
        fout<<ans[ i ]<<' ';
    }
    return 0;
}