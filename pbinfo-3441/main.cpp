/*======================================================================================
 * Autor: stud. Iordache Ioan-Bogdan, Universitatea din Bucuresti
 * Complexitate: O(N*M*K)
 * Punctaj asteptat: 90p
 *====================================================================================*/
#include <fstream>
#include <iostream>
using namespace std;
const int DIM = 505;
const long long INF = (1LL << 62);
int n, m, k, a[DIM][DIM];
long long sum[DIM][DIM], v[DIM];
int st, dr;
int deq[DIM];
int main()
{
#ifndef TESTING
    ifstream cin("cetate.in");
    ofstream cout("cetate.out");
#endif
    int op;
    cin >> op;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    long long best = -INF;
    int h1 = 0, w1 = 0, h2 = 0, w2 = 0;
    if (op == 1) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                long long curr = sum[i][j] - sum[i - k][j] - sum[i][j - k]
                    + sum[i - k][j - k];
                if (curr > best) {
                    best = curr;
                    h1 = i - k + 1, w1 = j - k + 1, h2 = i, w2 = j;
                }
            }
        }
        cout << best << '\n';
        cout << h1 << ' ' << w1 << ' ' << h2 << ' ' << w2 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] = a[i][j] + sum[i - 1][j];
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int i2 = i1; i2 < i1 + k && i2 <= n; ++i2) {
            for (int j = 1; j <= m; ++j)
                v[j] = v[j - 1] + sum[i2][j] - sum[i1 - 1][j];
            st = 1;
            dr = 1;
            deq[1] = 0;
            for (int j = 1; j <= m; ++j) {
                if (deq[st] == j - k - 1)
                    st++;
                long long curr = v[j] - v[deq[st]];
                if (best < curr || (best == curr && i1 == h1 && deq[st] + 1 < w1)) {
                    best = curr;
                    h1 = i1, w1 = deq[st] + 1, h2 = i2, w2 = j;
                }
                while (st <= dr && v[deq[dr]] > v[j])
                    dr--;
                deq[++dr] = j;
            }
        }
    }
    cout << best << '\n';
    cout << h1 << ' ' << w1 << ' ' << h2 << ' ' << w2 << '\n';
    return 0;
}