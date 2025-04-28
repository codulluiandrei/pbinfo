/*  100 puncte
    Complexitate: O(N^2 *K)
    Constantin Galatan
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("drumuri1.in");
ofstream fout("drumuri1.out");
const int Dim = 251;
const int MOD = 31607;
int L;
int m, n, K;
int nr[Dim][Dim][Dim]; // nr[i][j][k] - nr drumuri pana la poz (i, j) care trece prin k valori 1
short a[Dim][Dim], sl[Dim];
int main()
{
    fin >> n >> m >> K >> L;
    int x, y;
    for ( int i = 0; i < m; ++i )
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
    nr[0][1][0] = 1;
    int res = 0, pmax = min(L, K), imax = min(n, L);
    for ( int i = 1; i <= imax; ++i )
        for ( int j = 1; j <= n && i + j - 1 <= L; ++j )
            for ( int p = 0; p <= pmax && p <= i + j - 1; ++p )
                nr[i][j][p + a[i][j]] = (nr[i - 1][j][p] + nr[i][j - 1][p]) % MOD;
    for ( int i = 1; i <= imax; ++i )
    {
        res += nr[i][L - i + 1][K];
        if ( res > MOD )
            res -= MOD;
    }
    fout << res << '\n';
    fin.close();
    fout.close();
    return 0;
}