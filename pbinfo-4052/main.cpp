/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM_MAX = 1000;
int n, m;
int mat[NM_MAX + 2][NM_MAX + 2];
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
bool inside (int i, int j) {
    return (1 <= i && i <= n && 1 <= j && j <= m);
}
int dist[NM_MAX + 2][NM_MAX + 2];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    queue <pair <int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = -1;
            for (int d = 0; d < 4; d++) {
                int i1 = i + di[d], j1 = j + dj[d];
                if (inside(i1, j1) == true && mat[i][j] != mat[i1][j1]) {
                    dist[i][j] = 0;
                    break;
                }
            }
            if (dist[i][j] == 0) {
                q.push(make_pair(i, j));
            }
        }
    }
    while (q.empty() == false) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int i1 = i + di[d], j1 = j + dj[d];
            if (inside(i1, j1) == true && dist[i1][j1] == -1) {
                dist[i1][j1] = dist[i][j] + 1;
                q.push(make_pair(i1, j1));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}