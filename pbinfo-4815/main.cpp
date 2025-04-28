#include <bits/stdc++.h>
#define MOD 1999999973
///O(sigma * M * logN)
using namespace std;
const int Nmax = 100005;
int N, M, C, Ans;
int SirMin[30];
char A[Nmax];
unsigned long long Fact[30 * Nmax];
set <int> S[30];
ifstream f("anagrame.in");
ofstream g("anagrame.out");
void precl()    ///precalculam factorialele numerelor mai mici ca Nmax
{
    Fact[0] = 1;
    for (int i = 1; i < 26 * Nmax; i++)
        Fact[i] = (1LL * i * Fact[i-1])%MOD;
}
int elg(int a, int b)   ///exponentierea logaritmica
{
    int rez=1;
    while (b>1)
    {
        if (b%2==1)
            rez=(1LL *  rez * a)%MOD;
        a=(1LL * a * a)%MOD;
        b=b/2;
    }
    return (1LL * a * rez)%MOD;
}
void actualizez_min(int A[], int B[])
{
    int lg_A = 0, lg_B = 0;
    for (int i = 0; i <= 25; i++) {
        lg_A += A[i];
        lg_B += B[i];
    }
    bool ok = false;
    for (int i = 0; i <=25 && !ok; i++)
    {
        lg_A -= A[i];
        lg_B -= B[i];
        if (A[i] > B[i]) {
            if (lg_B > 0) ok = true;
            else break;
        }
        if (A[i] < B[i]) {
            if (lg_A > 0) break;
            else ok = true;
        }
    }
    if (ok)
        for (int i = 0; i <=25; i++) B[i] = A[i];
}
void Generare(int x, int y, int &Rez)
{
    int Range[30], P=1, Nr = 0;
    for (int i = 0; i<= 25; i++)
    {
        Range[i] = 0;
        auto it1 = S[i].lower_bound(x);
        if (it1 == S[i].end()) continue;
        auto it2 = S[i].upper_bound(y);
        if (it2 ==S[i].begin()) continue;
        it2--;
        Range[i] = *it2 - *it1;
        if (Range[i] < 0) Range[i] = 0;
        P = (1LL * P * Fact[Range[i]])% MOD;
        Nr += Range[i];
    }
    Rez =  (1LL * Fact[Nr] * elg(P, MOD - 2))%MOD;
    if (C==1) actualizez_min(Range, SirMin);
}
void load ()
{
    f >> C >> N >> M;
    assert (C==1 || C==2);
    assert (N <=100000);
    assert (M <= 100000);
    for (int i = 1; i <= N; i++)     /// initializam seturile care mentin pentru fiecare litera pozitiile din sir
    {
        f >> A[i];
        assert (islower(A[i]));
        S[A[i] - 'a'].insert(i);
    }
    for (int i = 0; i <=25; i++) SirMin[i] = 0;
    SirMin[25] = N * 30;
    A[N+1]='\n';
    for (int i = 1; i <=M; i++)
    {
        int x = 0, y, poz;
        char s[Nmax];
        f >> s;
        if (isdigit(s[0]))         ///operatie generare
        {
            for (int j=0; s[j]; j++)
                x = x*10 + (int)s[j] - '0';
            f>>y;
            assert (x<=y);
            assert (y<=N);
            Generare(x, y, Ans);
            if (C==2) g << Ans << '\n';
        }
        else                     /// operatie update
        {   assert(islower(s[0]));
            f >> poz;
            S[A[poz]-'a'].erase(poz);
            S[s[0]-'a'].insert(poz);
            A[poz] = s[0];
        }
    }
    if (C==1)
    {
        for (int i = 0; i <= 25; i++)
            for (int j = 1; j<= SirMin[i]; j++)
                g<<(char)(i + 'a');
        g <<  '\n';
    }
}
int main()
{
    precl();
    load();
    return 0;
}