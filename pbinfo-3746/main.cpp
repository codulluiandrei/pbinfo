/* Author: Tulba-Lecu Theodor-Gabriel
 * Problem: lemans - 100p
 * Time Complexity: O(N * M * log(N * M))
 * Space Complexity: O(N * M)
 */
#include <algorithm>
#include <stdio.h>
#define MaxN 1005
#define INF (1LL << 60)
using namespace std;
FILE *file_in = fopen("lemans.in", "r");
FILE *file_out = fopen("lemans.out", "w");
int N, M, T, L, fr[MaxN], v[MaxN], p[MaxN], out[MaxN];
int active, left = 1, right, best_left, best_right;
long long ans = INF;
pair<long long, pair<int, int>> pos[MaxN * MaxN];
int main() {
    fscanf(file_in, "%d %d %d", &T, &N, &M);
    for (int i = 1; i <= N; i++) {
        fscanf(file_in, "%d", &v[i]);
    }
    for (int i = 1; i <= M; i++) {
        fscanf(file_in, "%d", &p[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pos[++L] = make_pair(1LL * T * v[i] + p[j], make_pair(i, j));
        }
    }
    sort(pos + 1, pos + 1 + L);
    for (right = 1; right <= L; right++) {
        fr[pos[right].second.first]++;
        if (fr[pos[right].second.first] == 1)
            active++;
        while (fr[pos[left].second.first] > 1) {
            fr[pos[left].second.first]--;
            left++;
        }
        if (active == N) {
            if (ans > pos[right].first - pos[left].first) {
                ans = pos[right].first - pos[left].first;
                best_left = left;
                best_right = right;
            }
        }
    }
    for (int i = best_left; i <= best_right; i++) {
        out[pos[i].second.first] = pos[i].second.second;
    }
    fprintf(file_out, "%lld\n", ans);
    for (int i = 1; i <= N; i++) {
        fprintf(file_out, "%d", out[i]);
        if (i < N) {
            fprintf(file_out, " ");
        }
    }
    return 0;
}