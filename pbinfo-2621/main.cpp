#include <bits/stdc++.h>
using namespace std;
ifstream f("spower2.in");
ofstream g("spower2.out");
int n, N;
long long x;
long long a[1001];
long long cb(long long x)
{
    int i = 1, j = N, m;
    while (i < j){
        m = (i+j) / 2;
        if ( a[m] < x ) i = m+1;
        else j = m;
    }
    m = (i+j) / 2;
    if (a[m] < x) return a[m+1];
             else return a[m];
}
int main()
{
    /// precalculare
    for(int i = 0; i < 31; ++i)
        for(int j = i+1; j < 31; ++j)
            a[++N] = (1 << i) + (1 << j);
    sort(a+1, a+N+1);
    f >> n;
    while (f >> x){
        g << cb(x) << ' ';
    }
    g << '\n';
    return 0;
}