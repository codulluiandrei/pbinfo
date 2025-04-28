#include <fstream>
using namespace std;
int x[10], n, m;
ifstream fin ("2genc.in");
ofstream fout("2genc.out");
void backtrack(int pas) {
    if (pas > m) {
        for (int i=1;i<=m;i++)
            fout<<x[i]<<" ";
        fout<<"\n";
    } else {
        int start = 1;
        if (pas > 1) {
            start = x[pas-1]-1;
            if (start < 1)
                start = 1;
        }
        for (int i=start;i<=n;i++) {
            x[pas] = i;
            backtrack(pas+1);
        }
    }
}
int main () {
    fin>>n>>m;
    backtrack(1);
    return 0;
}