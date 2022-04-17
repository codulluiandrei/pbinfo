#include <fstream>
using namespace std;
ifstream in("sminus.in");
ofstream out("sminus.out");
int n, v[100001], suma_maxim = 0, suma_temp = 0, st = 1, sf = 1, inc = 1;
int main() {
	in >> n;
    for (int i = 1; i <= n; ++i)
    	in >> v[i];
    for (int dr = 1; dr <= n; ++dr) {
    	suma_temp = suma_temp + v[dr];
        if (suma_temp < 0) {
        	suma_temp = 0;
        	st = dr + 1;
        } if (suma_temp >= suma_maxim) {
        	suma_maxim = suma_temp;
        	inc = st; sf = dr;
        }
    } for (int i = inc; i <= sf; ++i)
        v[i] = v[i] * -1;
    suma_temp = 0;
    for (int i = 1; i <= n; ++i)
    	suma_temp = suma_temp + v[i];
    out << inc << " " << sf << "\n" << suma_temp;
    return 0;
}