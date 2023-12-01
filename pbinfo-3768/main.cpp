#include <fstream>

using namespace std;
int F[9], G[9], f[9], i, n, m, x, j;
int main () {
    ifstream fin ("taieri.in");
    ofstream fout("taieri.out");
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>x;
        for (j=8;j>=1;j/=2) {
            f[j] += x/j;
            x%=j;
        }
    }
    fin>>m;
    while (m--) {

        for (i=8;i>=1;i/=2) {
            F[i] = f[i];
        }

        fin>>G[1]>>G[2]>>G[4]>>G[8];
        int ok = 1;
        for (i=8;i>=1;i/=2) {
            if (G[i] > F[i]) {
                ok = 0;
                break;
            }
            F[i/2] += (F[i]-G[i])*2;
        }

        fout<<ok;
        if (m!=0)
            fout<<" ";
        else
            fout<<"\n";
    }
    return 0;
}
