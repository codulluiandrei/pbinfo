/*
 * Splatoon - O(N^2*logN)
 * Bogdan Iordache
 */
#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1505;
int N, M;
bool blocked[kMaxN][kMaxN];
int player_mat[kMaxN][kMaxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) cin >> blocked[i][j];
    cin >> M;
    for (int i = 1; i <= M; ++i) {
        int x, y;
        cin >> x >> y;
        player_mat[x][y] = 1;
    }
    // Determinam pentru fiecare celula libera care este timpul minim dupa care
    // va fi colorata. Cautam binar acest timp si verificam, folosind sume
    // partiale, daca exista vreun jucator in patratul centrat in celula
    // curenta, corespunzator timpului fixat.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            player_mat[i][j] += player_mat[i - 1][j] + player_mat[i][j - 1] -
                                player_mat[i - 1][j - 1];
    vector<int> times;
    times.reserve(N * N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (blocked[i][j]) continue;
            int lo = 0, hi = N;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int up = max(1, i - mid), down = min(N, i + mid);
                int left = max(1, j - mid), right = min(N, j + mid);
                int check =
                    player_mat[down][right] - player_mat[up - 1][right] -
                    player_mat[down][left - 1] + player_mat[up - 1][left - 1];
                // daca avem macar un jucator in acest patrat
                if (check > 0)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            times.push_back(lo);
        }
    }
    sort(times.begin(), times.end());
    times.push_back(-1);
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; ++i) {
        int p;
        cin >> p;
        cout << times[min(p - 1, int(times.size()) - 1)] << " \n"[i == Q];
    }
    return 0;
}