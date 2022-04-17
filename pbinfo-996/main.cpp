#include <fstream>
using namespace std;
ifstream in("div3.in");
ofstream out("div3.out");
int sumcif(int n) {
    int S = 0;
    while (n != 0) {
        S = S + n % 10;
        n = n / 10;
    } if (S % 3 == 0) return 1;
    else return 0;
} int main() {
    int n, v[1001];
    in >> n;
    for (int i = 1; i <= n; ++i) {
        in >> v[i];
        if (sumcif(v[i]))
            out << v[i] << " ";
    } return 0;
}
