/*
    Author: Rusu Daniel
    Complexity: O(N)
    Verdict: 100/100
*/
#include <fstream>
using namespace std;
ifstream fin("sir6.in");
ofstream fout("sir6.out");
int P, N, x, mx;
int main() {
    fin >> P >> N;
    int prec = -1;
    int app = 0;
    for(int i = 1; i <= N; ++i) {
        fin >> x;
        if(x != prec) {
            if(P == 2 && prec >= 0) {
                fout << prec << ' ' << app << ' ';
            }
            else {
                mx = max(mx, app);
            }
            prec = x;
            app = 1;
        }
        else {
            ++app;
        }
    }
    mx = max(mx, app);
    if(P == 1) {
        fout << mx;
    }
    else {
        fout << prec << ' ' << app;
    }
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}