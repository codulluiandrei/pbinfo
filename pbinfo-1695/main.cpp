#include <fstream>
#define DIMM 2010

using namespace std;

int S[DIMM], D[DIMM];
int n, m, i, j, a, b, t, k, x;

int main () {
    ifstream fin ("oglinda.in");
    ofstream fout("oglinda.out");
    fin>>n>>m;
    for (i=1;i<=m;i++) {
        fin>>t;
        if (t == 1) {
            k++;
            fin>>S[k]>>D[k];
        } else {
            fin>>a;
            for (j=k; j>=1; j--) {
                if (S[j] <= a && a <= D[j]) {
                    x = a - S[j];
                    a = D[j] - x;
                }
            }
            fout<<a<<"
";
        }
    }
    return 0;
}
