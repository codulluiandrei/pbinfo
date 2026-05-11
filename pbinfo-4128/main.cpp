/* Task: iluminat
 * Author: Tulba-Lecu Theodor-Gabriel
 * Time complexity: O(n^2 + n * k)
 * Space complexity: O(n^2)
 * Approach:
 * Task 1: keep an array with the coordinates of each
 *          value from 1 to n^2 so it is easy to find
 *          the maximum.
 * Task 2: same as task 1, only count the sum as well
 * Task 3: 2D partial sums over mat for O(1) query
 *          of a specific kxk square
 * Asserted input for checking test validity
 */
#include <algorithm>
#include <cassert>
#include <cstdio>
#define MAXN 1000
#define MAXNSQR 1000000
using namespace std;
int c, n, k;
long long max_sum;
char fr[MAXNSQR + 5];
pair<short, short> positions[MAXNSQR + 5];
int mat[MAXN + 5][MAXN + 5];
long long sum[MAXN + 5][MAXN + 5];
int main() {
    freopen("iluminat.in", "r", stdin);
    freopen("iluminat.out", "w", stdout);
    assert(scanf("%d%d%d", &c, &n, &k) == 3);
    assert(c == 1 || c == 2 || c == 3);
    assert(2 <= n && n <= MAXN);
    assert(1 <= k && k < n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            //            assert(scanf("%d", &mat[i][j]) == 1);
            //            assert(1 <= mat[i][j] && mat[i][j] <= n * n);
            //            assert(fr[mat[i][j]] == 0);
            fr[mat[i][j]]++;
            positions[mat[i][j]] = {i, j};
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
        }
    }
    int it = n * n, cell_sum;
    for (int i = 1; i <= k; i++) {
        while (fr[it] == 0) {
            it--;
        }
        cell_sum = 0;
        int x = positions[it].first, y = positions[it].second;
        for (int j = 1; j <= n; j++) {
            if (mat[x][j] != 0) {
                fr[mat[x][j]]--;
                cell_sum += mat[x][j];
                mat[x][j] = 0;
            }
            if (mat[j][y] != 0) {
                fr[mat[j][y]]--;
                cell_sum += mat[j][y];
                mat[j][y] = 0;
            }
        }
    }
    if (c == 1) {
        printf("%d\n", it);
    } else if (c == 2) {
        printf("%d\n", cell_sum);
    } else {
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                max_sum = max(max_sum, sum[i][j] - sum[i][j - k] -
                                           sum[i - k][j] + sum[i - k][j - k]);
            }
        }
        printf("%lld\n", max_sum);
    }
    return 0;
} 