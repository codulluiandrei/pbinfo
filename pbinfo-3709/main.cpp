/// Marius Nicoli, oficial
#include <fstream>

using namespace std;
int n, x, primul, ultimul, i, pozImpAntAnt, pozImpAnt, impare;
long long sumaCurenta, sumaAnterioara, minim, dif;

int main () {
    ifstream fin ("tri.in");
    ofstream fout("tri.out");


    fin>>n;
    minim = 2000000000;
    for (i=1;i<=n;i++) {
        fin>>x;
        if (x % 2 == 0)
            sumaCurenta += x;
        else {
            impare++;
            if (impare >= 3) {
                dif = sumaCurenta - sumaAnterioara;
                if (dif < 0)
                    dif = -dif;
                if (dif <= minim) {
                    minim = dif;
                    primul = pozImpAntAnt;
                    ultimul = i;
                }
            }
            pozImpAntAnt = pozImpAnt;
            pozImpAnt = i;
            sumaAnterioara = sumaCurenta;
            sumaCurenta = 0;
        }
    }
    fout<<primul<<" "<<ultimul;
    return 0;
}
