#include <fstream>
#include <vector>
#define DIM 50010
using namespace std;
vector <int> L[DIM];
int d[DIM];
int c[DIM];
int f[DIM];
int n, m, k, p, maxim, x, y, cost;
void bfs(int start) {
    int p = 1, u = 1;
    f[k] = 1;
    c[1] = k;
    while(p <= u) {
        int nod = c[p];
        for (int i=0;i<L[nod].size();i++) {
            int vecin = L[nod][i];
            if (f[vecin] == 0) {
                f[vecin] = 1;
                c[++u] = vecin;
                d[vecin] = 1 + d[nod];
            }
        }
        p++;
    }
}
int main () {
    ifstream fin ("genius.in");
    ofstream fout("genius.out");
    fin>>n>>m;
    for (int i=1;i<=m;i++) {
        fin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    fin>>k;
    fin>>p;
    bfs(k);
    for (int i=1;i<=n;i++)
        if(f[i] == 0) {
            fout<<-1;
            return 0;
        }
    for (int i=1;i<=n;i++)
        if (d[i] > maxim)
            maxim = d[i];
    fout<<maxim + p;
    return 0;
}