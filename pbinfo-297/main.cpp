#include <fstream>
using namespace std;
ifstream in("secvsummax.in");
ofstream out("secvsummax.out");
int main() {
	int n, v[100001], suma_maxim, suma_temp, poz_temp = 1, inc = 1, sf = 1;
	in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    suma_maxim = v[1], suma_temp = v[1];
    for (int i = 2; i <= n; ++i) {
        if (suma_temp < 0) {
        	suma_temp = v[i];
        	poz_temp = i;
        } else suma_temp = suma_temp + v[i];
        if (suma_temp > suma_maxim) {
        	suma_maxim = suma_temp;
            inc = poz_temp;
            sf = i;
        }
    } out << inc << " " << sf;
    return 0;
}
