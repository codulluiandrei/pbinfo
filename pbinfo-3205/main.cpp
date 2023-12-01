#include <fstream>

using namespace std;
int v[1002];
int n, p1, p2;

ifstream fin ("calcfunct.in");
ofstream fout("calcfunct.out");

int maxim(int v[], int n) {
    int r = v[1];
    int p = 1;
    for (int i=2;i<=n;i++) {
        if (v[i] > r) {
            r = v[i];
            p = i;
        }
    }
    return p;
}

void minim(int v[], int n, int &p) {
    int r = v[1];
    p = 1;
    for (int i=2;i<=n;i++) {
        if (v[i] < r) {
            r = v[i];
            p = i;
        }
    }
}

void schimba(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void afiseaza(int v[], int pozInit, int pozFin) {
    for (int i=pozFin;i>=pozInit;i--)
        fout<<v[i]<<" ";
    fout<<"\n";
}

int main () {

    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>v[i];
    p1 = maxim(v, n);
    minim(v, n, p2);

    if (p1 > p2)
        schimba(p1, p2);

    afiseaza(v, p1, p2);

}
