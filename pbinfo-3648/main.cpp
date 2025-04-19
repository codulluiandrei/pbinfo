/* Pitici - O(NlogN)
 * Dana Lica
 * scor: 100
 */
#include <fstream>
using namespace std;
ifstream f("pitici.in");
ofstream g("pitici.out");
using ll = long long;
const int NMAX = 2e5 + 1;
int N, A[NMAX], Mars[NMAX];
ll B, sp[NMAX];
static inline void Load ()
{
    f.tie(nullptr);
    f >> N;
    for(int i = 1; i <= N; ++i)
        f >> A[i], sp[i] = sp[i - 1] + 1LL * A[i];
    return;
}
static inline ll Query (int Left, int Right)
{
    return sp[Right] - sp[Left - 1];
}
static inline int Find (int Index, ll Needed)
{
    if(Query(Index, N) < Needed)
        return N;
    if(A[Index] == Needed)
        return Index;
    int Left = Index, Right = N, ans = N;
    while(Left <= Right)
    {
        int Mid = ((Left + Right) >> 1);
        if(Query(Index, Mid) >= Needed)
            ans = Mid, Right = Mid - 1;
        else
            Left = Mid + 1;
    }
    return ans;
}
static inline void Update (int Left, int Right, int Val)
{
    Mars[Left] += Val;
    if(Right < N)
        Mars[Right + 1] -= Val;
    return;
}
static inline void Solve ()
{
    for(int i = 1; i <= N; ++i)
    {
        f >> B;
        int poz = Find(i, B);
        Update(i, poz, +1);
    }
    return;
}
static inline void Write ()
{
    int ans = -1, cnt = 0;
    for(int i = 1; i <= N; ++i)
    {
        Mars[i] += Mars[i - 1];
        if(Mars[i] > ans)
            ans = Mars[i], cnt = 1;
        else if(Mars[i] == ans)
            ++cnt;
    }
    g << ans << ' ' << cnt << '\n';
    return;
}
int main()
{
    Load();
    Solve();
    Write();
    return 0;
} 