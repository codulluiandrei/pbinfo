#include <fstream>
using namespace std;
ifstream in("ursulet.in");
ofstream out("ursulet.out");
int main() {
    int n, v[100001], inc, sf, suma_temp = -1, suma_maxim = -2000000000, inc_temp;
    in >> n;
    for (int i = 1; i <= n; ++i) {
        in >> v[i];
    } for (int i = 1; i <= n; ++i) {
        if (suma_temp < 0) {
            suma_temp = 0;
            inc_temp = i;
        } suma_temp = suma_temp + v[i];
        if (suma_temp > suma_maxim) {
            inc = inc_temp; sf = i;
            suma_maxim = suma_temp;
        }
    } out << suma_maxim << "\n";
    out << inc << " " << sf;
    return 0;
}