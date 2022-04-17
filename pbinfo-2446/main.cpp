#include <fstream>
using namespace std;
ifstream in("numere24.in");
ofstream out("numere24.out");
long long C, x, k, n, oglinda, temp, nr;
int main() {
    in >> C;
    if (C == 1) {
        in >> n;
        out << (n - 1) * 10 << '\n';
        return 0;
    } if (C == 2) {
        in >> x;
        for (int i = 1; i <= 3; i++) {
            x = x / 10;
            oglinda = 0;
            temp = x;
            while (temp != 0) {
                oglinda = oglinda * 10 + temp % 10;
            	temp = temp / 10;
        	} if (oglinda == x) nr = 1;
            else if (x % 10 == 0) nr = 0;
            else nr = 2;
            out << nr << " ";
        } return 0;
     } in >> k;
     if (k == 1) {
         out << 9 << '\n';
         return 0;
     } if (k == 2) {
         out << 153 << '\n';
         return 0;
     } if (k == 3) {
         out << 1530 << '\n';
         return 0;
     } if (k == 4) {
         out << 16110 << '\n';
         return 0;
     } x = (k - 1) / 2;
     out << 161;
     for (int i = 1; i <= k - x - 3; i++) out << 9;
     out << 1;
     for (int i = 1; i <= x; i++) out << 0;
    return 0;
}
