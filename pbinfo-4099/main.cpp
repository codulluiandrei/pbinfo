/**
*   David Coroian
*   Problema Transport
*/
#include <bits/stdc++.h>
#define MAX_N 500000
using namespace std;
typedef long long lint;
const lint MOD = (lint)(1e9) + 7;
inline void modd(lint &a)
{
    if(a >= MOD)
        a -= MOD;
    if(a < 0)
        a += MOD;
}
inline void modd(int &a)
{
    if(a >= MOD)
        a -= MOD;
    if(a < 0)
        a += MOD;
}
unordered_map <lint, lint> ap;
unordered_map <lint, int> last;
lint rez;
lint c;
int q, n;
lint d[MAX_N + 1];
lint a[MAX_N + 1];
lint p2x[MAX_N + 1];
void readFile()
{
    ifstream f("transport.in");
    f >> q;
    f >> n >> c;
    for(int i = 1; i <= n; i ++)
        f >> a[i] >> d[i];
    f.close();
}
void upd(lint x, int i)
{
    ap[x] = ap[x] * p2x[i - last[x]] % MOD;
}
void add(lint x, int i)
{
    upd(x, i);
    ap[x] ++;
    modd(ap[x]);
    last[x] = i;
}
void inc(lint x)
{
    ap[x] ++;
}
void getP2()
{
    p2x[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        p2x[i] = p2x[i - 1] << 1;
        modd(p2x[i]);
    }
}
void solve()
{
    getP2();
    for(int i = 1; i <= n; i ++)
    {
        rez += (q == 1 ? ap[c * a[i] - d[i]] : ap[c * a[i] - d[i]] * p2x[i - last[c * a[i] - d[i]] - 1] % MOD);
        modd(rez);
        (q == 1 ? inc(c * a[i] + d[i]) : add(c * a[i] + d[i], i));
    }
}
void printFile()
{
    ofstream g("transport.out");
    g << rez << "\n";
    g.close();
}
int main()
{
    readFile();
    solve();
    printFile();
    return 0;
}