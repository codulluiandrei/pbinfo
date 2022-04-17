#include <fstream>
using namespace std;
ifstream in("secvente.in");
ofstream out("secvente.out");
int main() {
    int n, v[10001], nr = 0;
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    for (int i = 2; i <= n; ++i)
        if (v[i] < v[i - 1])
            nr++;
    if (v[n] > v[n - 1])
        nr++;
    out << nr;
    return 0;
}
