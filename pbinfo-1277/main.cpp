#include <fstream>
using namespace std;
int n, m, v[10];
ifstream in("produscartezian1.in");
ofstream out("produscartezian1.out");
void afisare(int k) {
    for (int i = 1; i <= k; ++i)
        out << v[i] << " ";
    out << "\n";
}
void backtracking(int k) {
    for (int i = 1; i <= n; ++i) {
        v[k] = i;
        if (k == m) afisare(k);
        else backtracking(k + 1);
    }
}
int main() {
    in >> n >> m;
    backtracking(1);
    return 0;
}