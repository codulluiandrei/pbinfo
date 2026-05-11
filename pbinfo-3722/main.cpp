///Bogdan-Ioan Popa
///100p
#include <bits/stdc++.h>
#define MOD 666013
#define N_MAX 10
using namespace std;
ifstream fin("logic.in");
ofstream fout("logic.out");
int t;
int N, Q;
int L;
char op[1 << N_MAX];
int E[1 << N_MAX];
int cnt[1 << N_MAX][2];
int main()
{
    fin >> t;
    fin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= (1 << i); j++) {
            fin >> op[++L];
        }
    }
    if(t == 1) {
        for(fin >> Q; Q; Q--) {
            for(int i = 1; i <= (1 << N); i++) {
                char c;
                fin >> c;
                E[L + i] = c - '0';
            }
            for(int i = L; i >= 1; i--) {
                if(op[i] == '|') {
                    E[i] = E[2 * i] | E[2 * i + 1];
                }
                else {
                    E[i] = E[2 * i] & E[2 * i + 1];
                }
            }
            fout << E[1] << "\n";
        }
    }
    else {
        int result;
        fin >> result;
        for(int i = 1; i <= (1 << N); i++) {
            cnt[L + i][0] = cnt[L + i][1] = 1;
        }
        for(int i = L; i >= 1; i--) {
            for(int le = 0; le <= 1; le++) {
                for(int ri = 0; ri <= 1; ri++) {
                    if(op[i] == '|') {
                        cnt[i][le | ri] = (cnt[i][le | ri] + 1ll * cnt[2 * i][le] * cnt[2 * i + 1][ri]) % MOD;
                    }
                    else {
                        cnt[i][le & ri] = (cnt[i][le & ri] + 1ll * cnt[2 * i][le] * cnt[2 * i + 1][ri]) % MOD;
                    }
                }
            }
        }
        fout << cnt[1][result] << "\n";
    }
    return 0;
}