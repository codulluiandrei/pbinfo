#include <fstream>
using namespace std;
ifstream fin ("carti2.in");
ofstream fout ("carti2.out");
const int N = 1e5 + 5;
long long sp[N], n, a, b, k;
int main() {
    fin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        long long x;
        fin >> x;
        sp[i] = sp[i-1] + x;
    }
    for (int i = 1; i <= n; ++i) {
        int sol = i, step = 1 << 16;
        for (; step; step >>= 1)
            if (sol + step <= n && sp[sol + step] - sp[i-1] <= k)
                sol += step;
        if (sp[sol] - sp[i-1] <= k && sp[sol] - sp[i-1] > sp[b] - sp[a-1])
            a = i, b = sol;
    }
    fout << a << " " << b;
}