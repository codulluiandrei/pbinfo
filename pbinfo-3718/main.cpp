#include <fstream>
#define DIM 400010
using namespace std;
int v[DIM];
int f[DIM];
int n, s, i, sol, j;
int main () {
    ifstream fin ("tort.in");
    ofstream fout("tort.out");
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>v[i];
    int s = 0;
    for (i=n;i>=2;i--) {
        s += v[i];
        f[s] = i;
    }
    for (i=1;i<=s;i++) {
        for (j=i;j<=s;j+=i) {
            if (f[j] == 0) {
                break;
            } else {
                sol++;
            }
        }
    }
    fout<<sol<<"\n";
    fout.close();
    return 0;
}