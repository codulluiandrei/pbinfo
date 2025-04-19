/**
Autor: Bogdan-Ioan Popa, FMI Universitatea din Bucuresti
Scor: 100p
**/
#include <bits/stdc++.h>
#define N_MAX 60
using namespace std;
ifstream fin("patratele.in");
ofstream fout("patratele.out");
int N, M, t;
int A[N_MAX + 5][N_MAX + 5];
int up[N_MAX + 5][N_MAX + 5];
int ri[N_MAX + 5][N_MAX + 5];
int dwn[N_MAX + 5][N_MAX + 5];
int le[N_MAX + 5][N_MAX + 5];
int ans[N_MAX + 5];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int dir[] = {2, 3, 0, 1};
int p2[] = {1, 2, 4, 8};
char side[][8] = {
    "SUS",
    "DREAPTA",
    "JOS",
    "STANGA"
};
bool check_side(int conf, int side) {
    return conf / p2[side] % 2;
}
void flip_side(int &conf, int side) {
    if(check_side(conf, side)) {
        conf -= p2[side];
    }
    else {
        conf += p2[side];
    }
}
int compute_ans() {
    memset(ans, 0, sizeof(ans));
    memset(le, 0, sizeof(le));
    memset(ri, 0, sizeof(ri));
    memset(up, 0, sizeof(up));
    memset(dwn, 0, sizeof(dwn));
    int total_ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(check_side(A[i][j], 1)) {
                up[i][j] = 1 + up[i - 1][j];
            }
            if(check_side(A[i][j], 2)) {
                le[i][j] = 1 + le[i][j - 1];
            }
        }
    }
    for(int i = N; i >= 1; i--) {
        for(int j = M; j >= 1; j--) {
            if(check_side(A[i][j], 0)) {
                ri[i][j] = 1 + ri[i][j + 1];
            }
            if(check_side(A[i][j], 3)) {
                dwn[i][j] = 1 + dwn[i + 1][j];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int max_k = min(min(dwn[i][j], ri[i][j]), min(N - i + 1, M - j + 1));
            for(int k = 1; k <= max_k; k++) {
                int ii = i + k - 1;
                int jj = j + k - 1;
                if(k <= up[ii][jj] && k <= le[ii][jj]) {
                    ans[k]++;
                    total_ans++;
                }
            }
        }
    }
    return total_ans;
}
int main()
{
    fin >> N >> M >> t;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            fin >> A[i][j];
        }
    }
    int sol = compute_ans();
    if(t == 3) {
        int max_ans = sol;
        int ans_i, ans_j, ans_d;
        bool ok = false;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                for(int d = 0; d < 4; d++) {
                    if(!check_side(A[i][j], d)) {
                        int ii = i + di[d];
                        int jj = j + dj[d];
                        flip_side(A[i][j], d);
                        flip_side(A[ii][jj], dir[d]);
                        int curr = compute_ans();
                        flip_side(A[i][j], d);
                        flip_side(A[ii][jj], dir[d]);
                        if(max_ans < curr) {
                            ok = true;
                            max_ans = curr;
                            ans_i = i;
                            ans_j = j;
                            ans_d = d;
                        }
                    }
                }
            }
        }
        if(!ok) {
            fout << "0\n0 0 NU\n";
        }
        else {
            fout << max_ans << "\n" << ans_i << " " << ans_j << " " << side[ans_d] << "\n";
        }
    }
    else {
        if(t == 1) {
            fout << sol << "\n";
        }
        else {
            for(int i = 1; i <= N; i++) {
                if(ans[i] != 0) {
                    fout << i << " " << ans[i] << "\n";
                }
            }
        }
    }
    return 0;
}