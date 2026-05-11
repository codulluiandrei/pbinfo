/**
Autor: Bogdan-Ioan Popa
Complexitate: O(N)
Scor: 100p
**/
#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 666013
#define N_MAX 1000000
#define ll long long
using namespace std;
ifstream fin("changemin.in");
ofstream fout("changemin.out");
int T, N;
int A[N_MAX + 5];
int L;
int S[N_MAX + 5];
int main()
{
    fin >> T >> N;
    for(int i = 1; i <= N; i++) {
        fin >> A[i];
        assert(A[i] >= 1 && A[i] <= 1000000000);
    }
    assert(T == 1 || T == 2);
    assert(1 <= N && N <= 1000000);
    ll cnt = 0;
    for(int i = N; i >= 1; i--) {
        while(L && A[S[L]] >= A[i]) {
            L--;
        }
        S[++L] = i;
        cnt += L;
    }
    if(T == 1) {
        fout << cnt << "\n";
        return 0;
    }
    L = 0;
    ll sum_all = 0, sum_coef = 0;
    int score = 0;
    for(int i = N; i >= 1; i--) {
        while(L && A[S[L]] >= A[i]) {
            sum_coef -= sum_all;
            sum_all -= A[S[L]];
            L--;
        }
        S[++L] = i;
        sum_all += A[i];
        sum_coef += sum_all;
        cnt -= L;
        score = (score + (1ll * cnt * sum_all) % MOD + sum_coef % MOD) % MOD;
    }
    fout << score << "\n";
    return 0;
}