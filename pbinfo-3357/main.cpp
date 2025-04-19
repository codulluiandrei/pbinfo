#include <fstream>
using namespace std;
ifstream fin ("beta.in");
ofstream fout("beta.out");
int n, poz, dir, len;
int main () {
    fin>>n>>poz;
    if (poz >= 2*n) {
        fout<<-1;
        return 0;
    }
    dir = 0;
    len = n;
    while (poz > len) {
        poz -= len;
        dir = 1-dir;
        len /= 2;
    }
    if (dir == 0) {
        fout<<n-len+poz;
    } else {
        fout<<n-poz+1;
    }
    return 0;
}