#include <bits/stdc++.h>
#define Nmax 100010
#define lsb(x) ((x ^ (x - 1)) & x)
#define ll long long
using namespace std;
ifstream fin("permutariab.in");
ofstream fout("permutariab.out");
int N;
int A[Nmax];
int pos[Nmax];
int bit[Nmax];
ll ans;
void update(int pos, int val)
{
    for(; pos <= N; pos += lsb(pos))
        bit[pos] += val;
}
int query(int pos)
{
    int ret = 0;
    for(; pos >= 1; pos -= lsb(pos))
        ret += bit[pos];
    return ret;
}
int main()
{
    fin >> N;
    for(int i = 1; i <= N; i++)
    {
        int x;
        fin >> x;
        pos[x] = i;
    }
    for(int i = 1; i <= N; i++)
    {
        int x;
        fin >> x;
        A[i] = pos[x];
    }
    for(int i = N; i >= 1; i--)
    {
        ans += query(A[i]);
        update(A[i], 1);
    }
    fout << ans << "\n";
    return 0;
}