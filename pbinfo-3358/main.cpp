#include <fstream>
using namespace std;
int v[1010];
int n, minim, pMinim, i, j, k;
int main () {
    ifstream fin ("gama.in");
    ofstream fout("gama.out");
    fin>>n>>k;
    for (i=1;i<=n;i++)
        fin>>v[i];
    for (i=1;i<=n;i++) {
        minim = n+1;
        for (j=i;j<=n&&j-i<=k;j++)
            if (v[j] < minim) {
                minim = v[j];
                pMinim = j;
            }
        k-=(pMinim-i);
        for (j=pMinim-1;j>=i;j--)
            swap(v[j], v[j+1]);
    }
    for (i=1;i<=n;i++)
        fout<<v[i]<<" ";
    return 0;
}