#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 200005;
const int VMAX = 2000005;

bool c[VMAX + 1];
vector <int> prime, comp;
int n, k;

void ciur() {
    c[0] = c[1] = 1;
    for (int i = 4; i <= VMAX; i += 2) {
        c[i] = 1;
    }

    for (int i = 3; i * i <= VMAX; i += 2) {
        if (c[i] == 0) {
            for (int j = i * i; j <= VMAX; j = j + 2 * i) {
                c[j] = 1;
            }
        }
    }
}

bool valid(int sum) {
    int dr = comp.size() - 1, nr = 0;

    for (int st = 0; st < prime.size() && dr >= 0; ++st) {
        while (dr >= 0 && prime[st] + comp[dr] > sum) {
            --dr;
        }
        if (dr < 0) {
            break;
        }

        nr = nr + dr + 1;
        if (prime[st] + comp[dr] == sum) {
            --nr;
        }
        if (nr >= k) {
            return 0;
        }
    }

    return 1;
}

int bs(int st, int dr) {
    int last = st, mij;

    while (st <= dr) {
        mij = (st + dr) / 2;
        if (valid(mij)) {
            last = mij;
            st = mij + 1;
        } else {
            dr = mij - 1;
        }
    }

    return last;
}

int main()
{
    freopen("intergalactic.in", "r", stdin);
    freopen("intergalactic.out", "w", stdout);

    int x, q;
    ciur();

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        if (c[x] == 0) {
            prime.push_back(x);
        } else {
            comp.push_back(x);
        }
    }

    sort(prime.begin(), prime.end());
    sort(comp.begin(), comp.end());

    for (int i = 1; i <= q; ++i) {
        scanf("%d", &k);
        printf("%d\n", bs(prime[0] + comp[0], prime[prime.size() - 1] + comp[comp.size() - 1]));
    }

    return 0;
} 