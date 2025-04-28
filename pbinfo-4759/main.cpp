#include <bits/stdc++.h>
using namespace std;
ifstream fin("x3.in");
ofstream fout("x3.out");
typedef long long llint;
const int K = 20;
int c[K];
int main()
{
    int n, x;
    fin >> n;
    for( int i = 0; i < n; ++i )
    {
        fin >> x;
        for(int j = 0; j < K; ++j)
            if( x&(1<<j) )
                c[j]++;
    }
    llint ans = 0;
    for( int i = 0; i < K; ++i )
        ans += llint( c[i] )*( n-c[i] )*(1<<i);
    fout << ans << "\n";
    return 0;
}