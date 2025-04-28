/// Dana Lica - C.J. Ex. PH
#include <fstream>
#include <cstring>
#include <cassert>
using namespace std;
ifstream f("text.in");
ofstream g("text.out");
const int NMAX = 2e5 + 1;
const int INF = 1e9;
int P;
int T;
char V[NMAX];
int N, M;
int pal_Max = 0;
string Container, Sol;
int H[NMAX];
int K, Stack[NMAX];
int Left[NMAX], Right[NMAX];
void Read ()
{
    assert(f >> P);
    assert(P == 1 || P == 2 || P == 3);
    assert(f.get());
    bool spaces = 0;
    bool minn = 0;
    bool maxn = 0;
    bool en = 0;
    int TOTAL = 0;
    char Ch = 0;
    while(f.get(Ch))
    {
        if(Ch == '\n')
        {
            en = 1;
            break;
        }
        ++TOTAL;
        assert(Ch == ' ' || (Ch >= 'a' && Ch <= 'z') || (Ch >= 'A' && Ch <= 'Z'));
        spaces |= (Ch == ' ');
        minn |= (Ch >= 'a' && Ch <= 'z');
        maxn |= (Ch >= 'A' && Ch <= 'Z');
        if((Ch >= 'a' && Ch <= 'z') || (Ch >= 'A' && Ch <= 'Z'))
            V[++T] = Ch;
    }
    assert(spaces && minn && maxn && en);
    assert(TOTAL >= 2 && TOTAL <= 2e5);
    return;
}
void Max_Pal (string S)
{
    int Size = (int)S.size() - 1;
    /// LUNGIME == 1 (MODULO 2):
    for(int i = 1; i <= Size; ++i)
    {
        int lg = 1;
        int left = i - 1, right = i + 1;
        while(left >= 1 && right <= Size && S[left] == S[right])
            lg += 2, --left, ++right;
        string now;
        for(int pos = left + 1; pos < right; ++pos)
            now += S[pos];
        if(lg > pal_Max || (lg == pal_Max && now > Sol))
            pal_Max = lg, Sol = now;
    }
    ///
    /// LUNGIME == 0 (MODULO 2):
    for(int i = 1; i < Size; ++i)
        if(S[i] == S[i + 1])
        {
            int lg = 2;
            int left = i - 1, right = i + 2;
            while(left >= 1 && right <= Size && S[left] == S[right])
                lg += 2, --left, ++right;
            string now;
            for(int pos = left + 1; pos < right; ++pos)
                now += S[pos];
            if(lg > pal_Max || (lg == pal_Max && now > Sol))
                pal_Max = lg, Sol = now;
        }
    ///
    return;
}
int MAX (int a, int b)
{
    return ((a > b) ? a : b);
}
int main()
{
    Read();
    int Min = INF;
    for(int d1 = 1; d1 * d1 <= T; ++d1)
        if(T % d1 == 0)
        {
            int d2 = T / d1;
            if((d2 - d1) < Min)
                Min = (d2 - d1), N = d1, M = d2;
        }
    assert(N > 1);
    char A[N + 1][M + 1];
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            A[i][j] = V[((i - 1) * M + j)];
    if(P == 1)
    {
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
                g << A[i][j];
            g << '\n';
        }
        return 0;
    }
    if(P == 2)
    {
        for(int i = 1; i <= N; ++i)
        {
            Container = "0";
            for(int j = 1; j <= M; ++j)
                Container.push_back(A[i][j]);
            Max_Pal(Container);
        }
        for(int j = 1; j <= M; ++j)
        {
            Container = "0";
            for(int i = 1; i <= N; ++i)
                Container.push_back(A[i][j]);
            Max_Pal(Container);
        }
        g << Sol << '\n';
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            char X = A[i][j];
            if(X >= 'A' && X <= 'Z')
                X = tolower(X);
            if(X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u')
                ++H[j];
            else
                H[j] = 0;
        }
        K = 0;
        for(int j = 1; j <= M; ++j)
        {
            while(K && H[j] < H[Stack[K]])
                Right[Stack[K]] = j, --K;
            Stack[++K] = j;
        }
        for(int x = 1; x <= K; ++x)
            Right[Stack[x]] = (M + 1);
        K = 0;
        for(int j = M; j >= 1; --j)
        {
            while(K && H[j] < H[Stack[K]])
                Left[Stack[K]] = j, --K;
            Stack[++K] = j;
        }
        for(int x = 1; x <= K; ++x)
            Left[Stack[x]] = 0;
        for(int j = 1; j <= M; ++j)
        {
            int now = ((Right[j] - 1) - (Left[j] + 1) + 1);
            ans = MAX(ans, H[j] * now);
        }
    }
    g << ans << '\n';
    return 0;
}