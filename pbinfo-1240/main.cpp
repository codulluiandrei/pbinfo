#include <fstream>
using namespace std;
ifstream fin ("ab3.in");
ofstream fout ("ab3.out");
typedef unsigned long long ull;
int n;
ull a, b, st = 1 << 19;
int main() {
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a;
        ull b = 0;
        for (ull step = st; step; step >>= 1)
            if ((b + step) * (b + step) * (b + step) +(b + step) <= a)
                b += step;
        fout << b << "\n";
    }
}