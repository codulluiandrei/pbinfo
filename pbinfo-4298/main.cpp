#include <fstream>
using namespace std;
long long n, i, ant, crt, sol;
int main () {
    ifstream fin ("lacom.in");
    ofstream fout("lacom.out");
    fin>>n;
    fin>>ant;
    sol = ant;
    for (i=1;i<=n;i++) {
        fin>>crt;
        if (crt > ant) {
            sol += crt;
            ant = crt;
        }
    }
    fout<<sol<<"\n";
    return 0;
}