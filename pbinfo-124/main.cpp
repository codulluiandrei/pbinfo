#include <fstream>
using namespace std;
ifstream in("permutari1.in");
ofstream out("permutari1.out");
int n, x[10];
bool f[10];
void afisare() {
    for (int i = 1; i <= n; i++)
        out << x[i] << " ";
    out << '\n';
}
void back(int k) {
    if (k > n) {
        afisare();
        return;
    } else {
        for (int i = n; i >= 1; i--) {
            if (f[i] == 0) {
                x[k] = i;
                f[i] = true;
                back(k + 1);
                f[i] = false;
            }
        }
    }
}
int main() {
    in >> n;
    back(1);
    return 0;
}