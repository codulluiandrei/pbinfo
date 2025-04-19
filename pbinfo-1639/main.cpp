#define TuTTy "Cosmin-Mihai Tutunaru"
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#define infile "secvente.in"
#define outfile "secvente.out"
#define nMax 200013
#define vMax 1000013
using namespace std;
bool vz[vMax];
int v[nMax];
int pos[vMax];
int n;
void read() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+1]);
        assert(vz[v[i+1]] == false);
        vz[v[i+1]] = true;
    }
}
void solve() {
    int best = 0;
    for (int i = 1; i <= n; ++i) {
        int begin = v[i], end = v[i];
        if (pos[v[i]-1]) begin = pos[v[i]-1];
        if (pos[v[i]+1]) end = pos[v[i]+1];
        pos[begin] = end;
        pos[end] = begin;
        best = max(best, end - begin + 1);
        printf("%d\n", best);
    }
}
int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    read();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}