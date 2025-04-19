#include <fstream>
using namespace std;
long long N, Q, i, b;
int main () {
    ifstream fin ("bits.in");
    ofstream fout("bits.out");
    fin>>N>>Q;
    for (i=1;i<=Q;i++) {
        fin>>b;
        fout<<( (N>>b)&1 );
    }
    return 0;
}