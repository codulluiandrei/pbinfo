#include <fstream>
using namespace std;
ifstream in("platou2.in");
ofstream out("platou2.out");
int main() {
    int kmax = 0, k = 1, x, y, n;
    in >> n >> x;
    for (int i = 2; i <= n; i++) {
        in >> y;
        if (x < y) {
            x = y;
            k++;
        } else {
            kmax = max(kmax, k);
            x = y;
            k = 1;
        }
    } kmax = max(k, kmax);
    out << kmax;
    return 0;
}