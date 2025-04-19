#include <fstream>
using namespace std;
int f[1000000];
int v[10001];
int N, L, K, i, j, i1, i2, t, s, e, val;
int main () {
    ifstream fin ("selectare.in");
    ofstream fout("selectare.out");
    fin>>N>>L>>K;
    for (i=1;i<=N;i++)
        fin>>v[i];
    for (s = L-K; s <= L; s++) {
        for (i=1;i+s-1<=N;i++) {
            /// consideram secventa care incepe la pozitia i si se termina
            /// la pozitia i+s-1
            /// si din care eliminam s-(L-K) elemente
            j = i+s-1;
            e = s-(L-K);
            if (e == 0) {
                val = 0;
                for (t=i;t<=j;t++)
                    val = val*10+v[t];
                f[val]++;
            }
            if (e == 1) {
                for (i1=i+1;i1<=j-1;i1++) {
                    val = 0;
                    for (t=i;t<=j;t++)
                        if (t!=i1)
                            val = val*10 + v[t];
                    f[val]++;
                }
            }
            if (e == 2) {
                for (i1=i+1;i1<j-1;i1++)
                    for (i2=i1+1;i2<j;i2++) {
                        val = 0;
                        for (t=i;t<=j;t++)
                            if (t!=i1 && t!=i2)
                                val = val * 10 + v[t];
                        f[val]++;
                    }
            }
        }
    }
    int p = 1, sol, maxim = 0;
    for (i=1;i<=L;i++)
        p = p*10;
    for (i=0;i<p;i++)
        if (f[i] > maxim) {
            maxim = f[i];
            sol = i;
        }
    fout<<sol;
    return 0;
}