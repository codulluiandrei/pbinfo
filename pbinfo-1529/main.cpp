#include <fstream>
using namespace std;
int main() {
    int n,z,g2,i, s, r, nr=0;
    long long g1, k;
    int G;
    char L;
    ifstream f("pesti.in");
    f>>n>>G>>z;
    k=G;
    s=z/7; r=z%7;
    ofstream h("pesti.out");
    for(i=1;i<=n;i++) {
        f>>L>>g1>>g2;
        g1=g1+7*g2*s*(s+1)/2+r*g2*(s+1);
        if (g1>=k) {
            h<<g1<<' '<<L<<'\n';
            nr++;
        }
    }
    if (nr==0) h<<0;
    h.close(); f.close();
    return 0;
}