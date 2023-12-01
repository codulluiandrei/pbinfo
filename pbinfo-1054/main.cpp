#include <fstream>

using namespace std;

int x, k, n, z, p, y, i, m;
int v[10010], w[10010];

int main() {
    ifstream fin("galbeni.in");
    ofstream fout("galbeni.out");
    fin>>x>>k>>n;
    v[x] = 1;
    z = 1;
    for (i=1;i<=k;i++)
        z = z * 10;
    w[1] = x;
    for (i=2;i<=n;i++) {
        y = x;
        p = x;
        while (y!=0) {

            if (y%10 != 0) {
                p = p * (y%10);
            }
            y = y/10;
        }
        p = p * 8;
        p = p/9;
        p = p%z;
        while (p*10 < z)
            p = p * 10 + 9;
        if (v[p]!=0) {
            m = n-(v[p]-1);
            m = m % (i-v[p]);
            if (m == 0) {
                fout<<w[i-1]<<"
";
            } else {
                fout<<w[v[p] + m - 1]<<"
";
            }
            return 0;
        }
        x = p;
        v[x] = i;
        w[i] = x;
    }
    fout<<w[n]<<"
";
    return 0;
}
