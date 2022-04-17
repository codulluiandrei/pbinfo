#include <fstream>
using namespace std;
ifstream in("platou3.in");
ofstream out("platou3.out");
int main() {
    int kmax = 0, k = 0, x, n;
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> x;
        if (x > 0)
            k++;
        else {
            kmax = max(kmax, k);
            k = 0;
        }
    } kmax = max(k, kmax);
    out << kmax;
    return 0;
}