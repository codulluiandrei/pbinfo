#include <fstream>
#include <queue>
using namespace std;
ifstream fin ("labirint.in");
ofstream fout ("labirint.out");
const int N = 1005;
const int dx[] = {-1, 0, 1, 0},
          dy[] = {0, 1, 0, -1};
int a[N][N], v[N][N], n, sol, step = 1 << 16;
queue <pair <int, int> > Q;
int lee(int k) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            v[i][j] = 0;
    if (a[1][1] <= k)
        Q.push(make_pair (1, 1));
    else
        return 0;
    while (Q.size() && !v[n][n]) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int crt = 0; crt < 4; ++crt) {
            int xx = x + dx[crt];
            int yy = y + dy[crt];
            if (!v[xx][yy] && a[xx][yy] <= k) {
                v[xx][yy] = 1;
                Q.push(make_pair (xx, yy));
            }
        }
    }
    while (Q.size())
        Q.pop();
    return v[n][n];
}
int main() {
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
            v[i][j] = 1;
    for (; step; step >>= 1)
        if (!lee(sol + step))
            sol += step;
    fout << sol + 1;
}