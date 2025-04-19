/* Solutie 100 p
   Complexitate O(n * n)
   prof. Constantin Galatan
*/
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
#define NMAX 1003
#define VMAX 5001
ifstream fin("cool.in");
ofstream fout("cool.out");
int cnt[NMAX], a[5001], nr[VMAX];
int T, K, n,  maxK,  minK = VMAX;
int L, Lmax = 1, nMaxCool, amin, amax, bad; // bad - nr de valori cu contor > 1 in intervalul[i, j]
int main()
{
    fin >> T >> n >> K;
    for (int i = 0; i < n; ++i)
    {
        fin >> a[i];
        if ( i < K )
        {
            maxK = max(maxK, a[i]), minK = min(minK, a[i]);
            nr[a[i]]++;
        }
    }
    if ( T == 1 )
    {
        bool cool = true; int distincte = 0;
        for ( int x = minK; x <= maxK; ++x )
        {
            if ( nr[x] == 0 || nr[x] > 1 )
                cool = false;
            if ( nr[x] == 1 ) distincte++;
        }
        if ( cool )
            fout << maxK << '\n';
        else
            fout << distincte << '\n';
    }
    else
    {
        for ( int i = 0; i < n; ++i )
        {
            cnt[a[i]]++, bad = 0;
            amin = amax = a[i];
            for ( int j = i + 1; j < n; ++j )
            {
                cnt[a[j]]++, L = j - i + 1;
                if ( cnt[a[j]] > 1 ) bad++;
                if ( amax < a[j] ) amax = a[j];
                if ( amin > a[j] ) amin = a[j];
                if ( bad ||  amax - amin != j - i )
                    continue;
                if ( L > Lmax )
                        Lmax = L, nMaxCool = 1;
                    else
                        if ( L == Lmax ) nMaxCool++;
            }
            cnt[a[i]]--;
            memset(cnt, 0, sizeof(cnt));
        }
        fout << Lmax << '\n' << nMaxCool << '\n';
    }
    return 0;
}