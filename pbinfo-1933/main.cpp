#include <fstream>
using namespace std;
ifstream in("sume2.in");
ofstream out("sume2.out");
long long int S[100004], n, m, temp, var;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i) {
		in >> temp;
        S[i] = S[i - 1] + temp;
    } in >> m;
    for (int i = 1; i <= m; ++i) {
        in >> temp >> var;
        out << S[var] - S[temp - 1] << "\n";
    } return 0;
}