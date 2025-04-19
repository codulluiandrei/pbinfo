#define TuTTy "Cosmin-Mihai Tutunaru"
#include <cstdio>
#include <vector>
#include <algorithm>
#define infile "bignumber.in"
#define outfile "bignumber.out"
#define nmax 1000013
#define ll long long
using namespace std;
int cnt[10];
int untestable[10];
vector<char> v; //the initial string
vector<char> w; //sorted version of w
vector<char> z; //used by getCost and moveLeft
int n, x;
void read() {
    scanf("%d %d\n", &n, &x);
    for (int i = 0; i < n; ++i) {
        char c;
        scanf("%c", &c);
        v.push_back(c);
    }
}
void printVector(vector<char> str) {
    for (size_t i = 0; i < str.size(); ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}
int getFirstPosAfter(int pos, int va) {
    for (int i = pos+1; i < n; ++i) {
        if (z[i] - '0' == va) {
            return i;
        }
    }
    return -1;
}
ll moveLeft(int pos, char c, int no) {
    ll cost = 0;
    int cnt = 0;
    for (int i = pos; i < (int)z.size(); ++i) {
        if (z[i] == c) {
            ++cnt;
        }
        if (cnt == no) {
            cnt = 0;
            for (int j = i; j >= pos; --j) {
                if (z[j] == c) {
                    ++cnt;
                } else {
                    z[j+cnt] = z[j];
                    cost += cnt;
                }
            }
            for (int j = 0; j < no; ++j) {
                z[pos+j] = c;
            }
            break;
        }
    }
    return cost;
}
ll getCost(int no) {
    ll cost = 0;
    z = v;
    for (int i = 0; i < no+1; ++i) {
        int pos = min(no + 1, i + cnt[w[i] - '0']);
        cost += moveLeft(i, w[i], pos - i);
        i = pos - 1;
    }
    return cost;
}
void solve() {
    for (size_t i = 0; i < v.size(); ++i) {
        cnt[v[i]-'0']++;
    }
    w = v;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    int le = 0, ri = n-1, best = -1;
    while(le <= ri) {
        int mi = (le+ri) / 2;
        if (getCost(mi) <= x) {
            best = mi, le = mi+1;
        } else {
            ri = mi - 1;
        }
    }
    if (best >= 0) {
        x -= getCost(best);
    } else {
        z = v;
    }
    for (int i = 0; i < best+1; ++i) {
        cnt[z[i] - '0']--;
    }
    for (int i = best+1; i < n && x; ++i) {
        for (int va = 9; va > z[i] - '0' && x; --va) {
            if (!cnt[va] || untestable[va] > i) {
                continue;
            }
            int pos = getFirstPosAfter(i, va);
            if (pos > i && pos - i <= x) {
                x -= pos - i;
                for (int j = pos - 1; j >= i; --j) {
                    z[j+1] = z[j];
                }
                z[i] = va + '0';
            } else {
                untestable[va] = x - (pos-1) - 1;
            }
        }
        cnt[z[i] - '0']--;
    }
}
void write() {
    printVector(z);
}
int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    read();
    solve();
    write();
    fclose(stdin);
    fclose(stdout);
    return 0;
}