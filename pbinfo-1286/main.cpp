#include <fstream>
using namespace std;
ifstream in("submultimi1.in");
ofstream out("submultimi1.out");
int n, m, v[10];
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        out << v[i] << " ";
    out << endl;
}
void backtracking(int k) {
    for (int i = v[k - 1] + 2; i <= n; ++i) {
        v[k] = i;
        afisare(k);
        backtracking(k + 1);
    }
}
int main() {
    in >> n >> m;
    v[0] = -1;
    backtracking(1);
    return 0;
}