#include <fstream>
#include <cmath>
using namespace std;
int maxim = -1;
int minim = 1000000001;
int n, x, y, r, i, j, nr1, nr2, sol, d, aux, e;
int main () {
    ifstream fin ("palpow.in");
    ofstream fout("palpow.out");
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>x;
        y = x;
        r = 0;
        while (y!=0) {
            r = r*10 + y%10;
            y = y/10;
        }
        nr1 = 1;
        aux = x;
        int rad = (int)sqrt(aux);
        for (d=2;aux!=1 && d<=rad;d++) {
            e = 0;
            while(aux%d == 0) {
                e++;
                aux /= d;
            }
            nr1 *= (e+1);
        }
        if (aux!=1)
            nr1 *= 2;
        nr2 = 1;
        aux = r;
        rad = (int)sqrt(aux);
        for (d=2;aux!=1 && d<=rad;d++) {
            e = 0;
            while(aux%d == 0) {
                e++;
                aux /= d;
            }
            nr2 *= (e+1);
        }
        if (aux!=1)
            nr2 *= 2;
        if (nr2 > nr1) {
            sol++;
            if (x > maxim)
                maxim = x;
            if (x < minim)
                minim = x;
        }
    }
    fout<<sol<<" "<<minim<<" "<<maxim<<"\n";
    return 0;
}