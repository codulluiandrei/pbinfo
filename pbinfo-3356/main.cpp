#include <fstream>
using namespace std;
int v[1001];
int n, x, p, i, j, aux, last;
int main () {
    ifstream fin ("alfa.in");
    ofstream fout("alfa.out");
    fin>>n>>x;
    for (i=1;i<=n;i++)
        fin>>v[i];
    last = n;
    for (p=n-1;p>=1;p--)
        if (v[p] == x) {
            int sortat;
            do {
                sortat = 1;
                for (i=p+1;i<=last-2;i++)
                    if (v[i] > v[i+1]) {
                        aux = v[i];
                        v[i] = v[i+1];
                        v[i+1] = aux;
                        sortat = 0;
                    }
            } while (sortat == 0);
            last = p;
        }
    for (i=1;i<=n;i++)
        fout<<v[i]<<" ";
    return 0;
}