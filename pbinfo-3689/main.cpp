#include <fstream>
using namespace std;
int x[10], n, m, f[10];
ifstream fin ("2gen.in");
ofstream fout("2gen.out");
void backtrack(int pas) {
    if (pas > m) {
        for (int i=1;i<=m;i++)
            fout<<x[i]<<" ";
        fout<<"\n";
    } else {
        for (int i=1;i<=n;i++) {
            if (f[i] < 2) {
                x[pas] = i;
                f[i]++;
                backtrack(pas+1);
                f[i]--;
            }
        }
    }
}
int main () {
    fin>>n>>m;
    backtrack(1);
    return 0;
}