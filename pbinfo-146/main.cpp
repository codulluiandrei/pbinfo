#define TuTTy "Cosmin-Mihai Tutunaru"
#include<cstdio>
#include<cassert>
#include<vector>
#define infile "graph.in"
#define outfile "graph.out"
#define nMax 1513
#define inf (1<<29)
using namespace std;
vector < pair<int, int> > v[nMax];
int dp[nMax];
int sorted[nMax];
int hash[nMax];
int ap[nMax];
int n, m;
void read() {
    scanf("%d %d
", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        v[x].push_back(make_pair(y, z));
        ap[y]++;
    }
}
int getNode() {
    for (int i = 1; i < n+1; ++i) {
        if (ap[i] == 0) {
            return i;
        }
    }
    assert(true == false);
    return -1;
}
void addNode(int x) {
    ap[x] = -1;
    for (unsigned i = 0; i < v[x].size(); ++i) {
        ap[v[x][i].first]--;
    }
}
void sort() {
    for (int i = 0; i < n; ++i) {
        int node = getNode();
        addNode(node);
        sorted[i] = node;
        hash[node] = i;
    }
}
void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j) {
            dp[j] = inf;
        }
        dp[i+1] = 0;
        for (int j = hash[i+1]; j < n; ++j) {
           int node = sorted[j];
           if (dp[node] == inf) {
               continue;
           }
           for (unsigned k = 0; k < v[node].size(); ++k) {
               assert(j < hash[v[node][k].first]);
               dp[v[node][k].first] = min(dp[v[node][k].first], dp[node] + v[node][k].second);
           }
        }
        for (int j = 1; j < n+1; ++j) {
            if (dp[j] == inf) {
                printf("x ");
            } else {
                printf("%d ", dp[j]);
            }
        }
        printf("\n");
    }
}
int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    read();
    sort();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}