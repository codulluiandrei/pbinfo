#include <fstream>
using namespace std;
ifstream in("varf.in");
ofstream out("varf.out");
int nr[15], v[15], n, ex;
void afisare(int k) {
    ex = 1;
    for (int i = 1; i <= k; i++)
        out << nr[v[i]] << " ";
    out << "\n";
}
int validare(int k) {
    int i = 3;
    if (k == 1) return 1;
    if (nr[v[1]] > nr[v[2]])return 0;
    if (k == 2) return 1;
    while ((nr[v[i - 1]] < nr[v[i]]) && (i <= k)) i++;
    if (i == k + 1) return 1;
    else if (nr[v[k - 1]] > nr[v[k]])return 1;
    return 0;
}
void backtracking(int k) {
    if (k <= n)
       for (v[k] = v[k - 1] + 1; v[k] <= n; v[k]++)
            if (validare(k)) {
                if (k >= 3 && nr[v[k - 1]] > nr[v[k]])
                    afisare(k);
                backtracking(k + 1);
            }
}
int main() {
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> nr[i];
    backtracking(1);
    if (ex == 0)
       out << "0";
    return 0;
}