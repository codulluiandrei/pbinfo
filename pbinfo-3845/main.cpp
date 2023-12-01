#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int NMAX = 1e6 + 5;

char s[NMAX], sol[NMAX];
bool viz[NMAX];
int n;

int main() {
    cin.sync_with_stdio(false);

    freopen("ciurulet.in", "r", stdin);
    freopen("ciurulet.out", "w", stdout);

    scanf("%d", &n);
    scanf("%s", s + 2);

    for (int i = 2; i <= n; i++) {
        if (!viz[i]) {
            if (s[i] == '0') {
                sol[i] = '0';
            } else if (s[i] == '1') {
                sol[i] = '1';
                for (int j = 2 * i; j <= n; j += i) {
                    viz[j] = 1;
                    sol[j] = '1';
                }
            } else {
                bool good_prime = 1;
                for (int j = 2 * i; j <= n; j += i) {
                    if (s[j] == '1') {
                        good_prime = 0;
                        break;
                    }
                }

                if (good_prime) {
                    sol[i] = '1';
                    for (int j = 2 * i; j <= n; j += i) {
                        viz[j] = 1;
                        sol[j] = '1';
                    }
                } else {
                    sol[i] = '0';
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (sol[i] == '1') ans++;

    printf("%d\n", ans);
    printf("%s\n", sol + 2);

    return 0;
}
