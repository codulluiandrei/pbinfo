#include <bits/stdc++.h>
#define N_MAX 1000
#define K_MAX 100000
#define INF (INT_MAX >> 1)
using namespace std;
ifstream fin("mindist.in");
ofstream fout("mindist.out");
int N, M, K;
queue < pair <int, int> > Q;
bool is_blocked[N_MAX + 5][N_MAX + 5];
int D[N_MAX + 5][N_MAX + 5];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
bool OK(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= N;
}
int main()
{
    fin >> N >> M >> K;
    while(M--) {
        int x, y;
        fin >> x >> y;
        is_blocked[x][y] = true;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            D[i][j] = INF;
        }
    }
    for(int i = 1; i <= K; i++) {
        int x, y;
        fin >> x >> y;
        D[x][y] = 0;
        Q.push({x, y});
    }
    while(!Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        for(int d = 0; d < 4; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if(OK(ii, jj) && D[ii][jj] > 1 + D[i][j] && !is_blocked[ii][jj]) {
                D[ii][jj] = 1 + D[i][j];
                Q.push({ii, jj});
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            fout << (D[i][j] == INF ? -1 : D[i][j]) << " ";
        }
        fout << "\n";
    }
    return 0;
}