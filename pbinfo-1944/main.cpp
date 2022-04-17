#include <fstream>
using namespace std;
ifstream in("suma6.in");
ofstream out("suma6.out");
int main() {
    int n, s = 0, nr = 0, x;
    int a, b, c;
    in >> n;
    for (int i = 1;i <= n; i++) {
        in >> x;
        int y = x, nrc = 0, p1 = 1, z = x;
        while (y != 0) {
            y = y / 10;
            nrc++;
            p1 = p1 * 10;
		} if (nrc != 3) {
            while (z > 9) z = z /10;
            int primacif = z;
            int p = 1;
            for (int j = 1; j <= nrc / 2; j++)
                p = p * 10;
            int cmj = (x / p) % 10;
            if (primacif == x % 10)
                s = s + cmj;
        } else {
        a = x / 100;
        b = x / 10 % 10;
        c = x % 10;
        if (a == c) {
            nr++;
            s = s + b;
            }
        }

    } out << s << "\n";
    return 0;
}