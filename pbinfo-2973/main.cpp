#include <fstream>

using namespace std;
int C[4], B[4];
int n, m, i, st, dr, mid, j, nr, baza, cifra, k, t;

ifstream fin ("cate3cifre.in");
ofstream fout("cate3cifre.out");

int main () {
    fin>>t>>n;

    for (i=n;i>=2;i--) {
        nr = 0;
        for (baza=2;1+baza+baza*baza<=i;baza++) {
            if (i%(1+baza+baza*baza) != 0)
                continue;

            cifra = i/(1+baza+baza*baza);
            if (cifra < baza) {
                nr++;
                C[nr] = cifra;
                B[nr] = baza;
                if (nr == 3)
                    break;
            }
        }
        if (nr == 2) {
            if (t == 1)
                fout<<i;
            else
                fout<<B[1]<<" "<<C[1]<<"\n"<<B[2]<<" "<<C[2]<<"\n";
            return 0;
        }
    }
}
