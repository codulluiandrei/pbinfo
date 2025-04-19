#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int NMAX = 100000;
const int VMAX = 1000000;
int v[NMAX + 5], f[VMAX + 5], n;
vector <int> d[NMAX + 5];
vector <int> sol;
int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve_fact(int poz, int x) {
    if (x % 2 == 0) {
        d[poz].push_back(2);
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    for (int i = 3; i * i <= x; ++i) {
        if (x % i == 0) {
            d[poz].push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        d[poz].push_back(x);
    }
}
void print_sol() {
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); ++i) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}
void solve_part() {
    int first = -1, last = -1;
    for (int i = 1; i < n; ++i) {
        if (v[i] == 1) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
        else if (v[i + 1] != 1 && gcd(v[i], v[i + 1]) == 1) {
            sol.push_back(i);
            v[i] = v[i + 1] = 1;
            if (first == -1) {
                first = i;
            }
            last = i + 1;
            ++i; // fortez trecerea la pasul urmator
        }
    }
    for (int i = first - 1; i > 0; --i) {
        sol.push_back(i);
        v[i] = 1;
    }
    for (int i = last + 1; i <= n; ++i) {
        sol.push_back(i - 1);
        v[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (v[i] != 1) {
            sol.push_back(i - 1);
            v[i] = 1;
        }
    }
    print_sol();
}
int valid(int len) {
    memset(f, 0, sizeof(f));
    int cnt = 0;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < d[i].size(); ++j) {
            ++f[d[i][j]];
            if (f[d[i][j]] == len) {
                ++cnt;
            }
        }
    }
    for (int i = len; i <= n; ++i) {
        for (int j = 0; j < d[i].size(); ++j) {
            ++f[d[i][j]];
            if (f[d[i][j]] == len) {
                ++cnt;
            }
        }
        if (cnt == 0) {
            return i - len + 1;
        }
        for (int j = 0; j < d[i - len + 1].size(); ++j) {
            --f[d[i - len + 1][j]];
            if (f[d[i - len + 1][j]] == len - 1) {
                --cnt;
            }
        }
    }
    return -1;
}
int main() {
    freopen("pian.in", "r", stdin);
    freopen("pian.out", "w", stdout);
    int t, ans;
    scanf("%d %d\n", &t, &n);
    scanf("%d", &v[1]);
    ans = v[1];
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &v[i]);
        ans = gcd(ans, v[i]);
    }
    if (t == 1) {
        printf("%lld\n", 1LL * n * ans);
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        v[i] /= ans;
        solve_fact(i, v[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (gcd(v[i], v[i + 1]) == 1) {
            solve_part();
            return 0;
        }
    }
    int st, dr, mij, last, pos_l, pos_r, rez;
    st = 3; dr = n;
    while (st <= dr) {
        mij = (st + dr) / 2;
        rez = valid(mij); /// Cautam o solutie pt lungimea mij
        if (rez != -1) {
            pos_l = rez;
            pos_r = rez + mij - 1;
            dr = mij - 1;
        } else {
            st = mij + 1;
        }
    }
    for (int i = pos_l; i < pos_r; ++i) {
        sol.push_back(i);
    }
    v[pos_r - 1] = 1;
    v[pos_r] = 1;
    for (int i = pos_r + 1; i <= n; ++i) {
        sol.push_back(i - 1);
        v[i] = 1;
    }
    for (int i = pos_r - 2; i > 0; --i) {
        sol.push_back(i);
        v[i] = 1;
    }
    print_sol();
    return 0;
}