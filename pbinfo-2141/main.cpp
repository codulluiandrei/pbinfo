#include <fstream>
using namespace std;
ifstream in("exp.in");
ofstream out("exp.out");
int f[5001];
int main() {
    int n, m, temp;
    bool adv = false;
    in >> m >> n;
    for (int i = 1; i <= n; ++i) {
        in >> temp;
        int d = 2;
        while (temp > 1) {
            int p = 0;
            while (temp % d == 0) {
            	p++;
            	temp = temp / d;
            } if (p != 0) f[d] = f[d] + p;
            d++;
            if (d * d > temp) d = temp;
        }
    } for (int i = 1; i <= 5000; i++)
        if (f[i] != 0)
            if (f[i] % m != 0) adv = true;
    if (adv == true) out << "0";
    else {
        out << "1" << "\n";
        for (int i = 1; i <= 100; ++i)
        	if (f[i] != 0)
        		out << i << " " << f[i] / m << "\n";
    } return 0;
}
