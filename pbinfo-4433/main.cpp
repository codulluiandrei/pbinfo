/*
    Autor: stud. Andrei Onut - Universitatea Yale, S.U.A.
    Problema: Kth
*/
#include <fstream>
using namespace std;
ifstream f("kth.in");
ofstream g("kth.out");
const int NMAX = 3e5 + 1;
const int absVMAX = 5e4;
const int ADD = absVMAX + 1;
const int DIM = 317;
int N, K, L;
int V[NMAX], Max = (int)(-1e5);
int ans[NMAX];
int fr[((absVMAX << 1) + 10)];
int M, cnt_bucket[(DIM + 5)];
int my_max(int a, int b)
{
    return ((a > b) ? a : b);
}
void Read()
{
    f >> N >> K >> L;
    for (int i = 1; i <= N; ++i)
        f >> V[i], V[i] += ADD, Max = my_max(Max, V[i]);
    return;
}
int Find(int pos)
{
    return (int)((pos + DIM - 1) / DIM);
}
void Modify(int X, int Val)
{
    fr[X] += Val;
    cnt_bucket[(int)(Find(X))] += Val;
    return;
}
int Find_Kth()
{
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= M; ++i)
    {
        sum += cnt_bucket[i];
        if (sum >= K)
        {
            int sum_prime = sum - cnt_bucket[i];
            int need = K - sum_prime;
            int left = ((i - 1) * DIM + 1), right = (i * DIM);
            for (int x = left; x <= right; ++x)
                if (fr[x] > 0)
                {
                    need -= fr[x];
                    if (need <= 0)
                    {
                        ans = x;
                        break;
                    }
                }
            break;
        }
    }
    return ans;
}
void Load()
{
    for (int i = 1; i <= L; ++i)
        Modify(V[i], +1);
    ans[1] = Find_Kth();
    return;
}
void Precalculation()
{
    M = Find(Max);
    Load();
    for (int i = 2; i <= (N - L + 1); ++i)
    {
        Modify(V[i - 1], -1);
        Modify(V[(i + L - 1)], +1);
        ans[i] = Find_Kth();
    }
    for (int i = 1; i <= (N - L + 1); ++i)
        ans[i] -= ADD;
    return;
}
void Test_Case()
{
    int pos = 0;
    f >> pos;
    g << ans[pos] << '\n';
    return;
}
void Solve()
{
    int Q = 0;
    f >> Q;
    for (int q = 1; q <= Q; ++q)
        Test_Case();
    return;
}
int main()
{
    Read();
    Precalculation();
    Solve();
    return 0;
} 