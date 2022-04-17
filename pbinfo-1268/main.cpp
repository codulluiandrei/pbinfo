#include <fstream>
using namespace std;
ifstream in("easyquery.in");
ofstream out("easyquery.out");
long long int n, v[100001], T, op, x, y, P, S = 0, smen[100002];
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    in >> T;
    for (int t = 1; t <= T; ++t) {
        in >> op >> x >> y >> P;
        if (op == 2) P = -P;
        smen[x] = smen[x] + P;
        smen[y + 1] = smen[y + 1] - P;
    } for (int i = 1; i <= n; ++i) {
        S = S + smen[i];
        v[i] = v[i] + S;
        out << v[i] << " ";
    } return 0;
}
// rezolvare cu smen, 100 pct