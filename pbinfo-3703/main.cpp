#include <fstream>
using namespace std;
ifstream f("potter.in");
ofstream g("potter.out");
const int NMAX = 2e3 + 1;
const int MOD = 1e9+7;
int N, M, T, K;
bool Line[NMAX], Column[NMAX];
int empty_cells;
static inline void Read ()
{
    f.tie(nullptr);
    f >> N >> M >> T >> K;
    for(int i = 1; i <= T; ++i)
    {
        int L = 0, C = 0;
        f >> L >> C;
        Line[L] = 1, Column[C] = 1;
    }
    return;
}
static inline void Load ()
{
    int l = 0, c = 0;
    for(int i = 1; i <= N; ++i)
        if(Line[i])
            ++l;
    for(int i = 1; i <= M; ++i)
        if(Column[i])
            ++c;
    empty_cells = N * M - (l * M + c * N - l * c);
    return;
}
static inline int lgput (int n, int p)
{
    int ans = 1, aux = n;
    for(int i = 0; (1 << i) <= p; ++i)
    {
        if(p & (1 << i))
            ans = (1LL * ans * aux) % (1LL * MOD);
        aux = (1LL * aux * aux) % (1LL * MOD);
    }
    return ans;
}
static inline int Comb (int n, int k)
{
    if(n < k)
        return 0;
    if(n == k)
        return 1;
    int ans = 1;
    for(int i = 2; i <= n; ++i)
        ans = (1LL * ans * i) % (1LL * MOD);
    int inv_mod = lgput(ans, MOD - 2);
    int last_mod = inv_mod;
    for(int i = (n - 1); i >= 1; --i)
    {
        inv_mod = (1LL * last_mod * (i + 1)) % (1LL * MOD);
        if(i == k)
            ans = (1LL * ans * inv_mod) % (1LL * MOD);
        if(i == (n - k))
            ans = (1LL * ans * inv_mod) % (1LL * MOD);
        last_mod = inv_mod;
    }
    return ans;
}
static inline void Solve ()
{
    g << Comb(empty_cells - 1 + K, empty_cells - 1) << '\n';
    g.close();
    return;
}
int main()
{
    Read();
    Load();
    Solve();
    return 0;
}