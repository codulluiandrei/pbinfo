#include <fstream>
using namespace std;

ifstream fin ("smen.in");
ofstream fout ("smen.out");

const int mod = 666013;

long long v[2] = {3}, n;

int main() {
    fin >> n;
    if (n >= 10000000) {
        v[0] = 22230;
        for (long long i = 10000001; i <= n; ++i) {
            v[1] = (v[0] * v[0] / (i + 2) + v[0] * i + i + 1) % mod;
            v[0] = v[1];
        }
        fout << v[0];
        return 0;
    }
    for (long long i = 1; i <= n; ++i) {
        v[1] = (v[0] * v[0] / (i + 2) + v[0] * i + i + 1) % mod;
        v[0] = v[1];
    }
    fout << v[0];
}
