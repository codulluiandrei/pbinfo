#include <fstream>
const char IN [ ] = "giovanacci.in";
const char OUT[ ] = "giovanacci.out";
const int MAX_MOD = 100000;
using namespace std;
ifstream cin ( IN );
ofstream cout( OUT );
int fib [ 4 * MAX_MOD + 1 ];
long long gcd ( long long a, long long b )
{
    return b ? gcd ( b, a % b ) : a;
}
int getPeriod ( int mod )
{
    fib [ 0 ] = 0;
    fib [ 1 ] = 1;
    int i = 2;
    do
    {
        fib [ i ] = ( fib [ i - 1 ] + fib [ i - 2 ] ) % mod;
        i ++;
    } while ( fib [ i - 1 ] != 1 || fib [ i - 2 ] != 0 );
    return i - 2;
}
int main ( void )
{
    int T, mod;
    int n;
    long long x, q;
    int period;
    cin >> T >> mod;
    period = getPeriod ( mod );
    while ( T -- )
    {
        cin >> n >> q;
        for ( int i = 1; i < n; i ++ )
        {
            cin >> x;
            q = gcd ( q, x );
        }
        cout << fib [ q % period ] << '\n';
    }
    return 0;
}