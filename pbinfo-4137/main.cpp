#include <fstream>
using namespace std;
ifstream fin("rgb.in");
ofstream fout("rgb.out");
const int NMAX = 500000;
int r[NMAX + 5], g[NMAX + 5], b[NMAX + 5];
int solve_task_1(int normal[], int weak[], int strong[]) {
    int p = normal[normal[0]], ans = normal[0] - 1;
    for (int w = 1; w <= weak[0]; ++w) {
        if (2 * p < weak[w]) {
            break;
        }
        ++ans;
    }
    for (int s = 1; s <= strong[0]; ++s) {
        if (p < 2 * strong[s]) {
            break;
        }
        ++ans;
    }
    return ans;
}
void solve_task_2(int normal[], int weak[], int strong[]) {
    int s = 1, w = 1;
    for (int n = 1; n <= normal[0]; ++n) {
        while (s <= strong[0] && strong[s] * 2 < normal[n]) {
            ++s;
        }
        while (w <= weak[0] && weak[w] < 2 * normal[n]) {
            ++w;
        }
        fout << n - 1 + s - 1 + w - 1 << " ";
    }
    fout << "\n";
}
int main()
{
    int t;
    fin >> t >> r[0] >> g[0] >> b[0];
    for (int i = 1; i <= r[0]; ++i) {
        fin >> r[i];
    }
    for (int i = 1; i <= g[0]; ++i) {
        fin >> g[i];
    }
    for (int i = 1; i <= b[0]; ++i) {
        fin >> b[i];
    }
    if (t == 1) {
        int w_r = solve_task_1(r, g, b);
        int w_g = solve_task_1(g, b, r);
        int w_b = solve_task_1(b, r, g);
        int ans = w_r, p = r[r[0]];
        if (w_g > ans || (w_g == ans && g[g[0]] < p)) {
            ans = w_g;
            p = g[g[0]];
        }
        if (w_b > ans || (w_b == ans && b[b[0]] < p)) {
            ans = w_b;
            p = b[b[0]];
        }
        fout << p << "\n";
    } else {
        solve_task_2(r, g, b);
        solve_task_2(g, b, r);
        solve_task_2(b, r, g);
    }
    fin.close();
    fout.close();
    return 0;
}