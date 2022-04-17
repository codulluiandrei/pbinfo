#include <fstream>
using namespace std;
ifstream in("bibinar.in");
ofstream out("bibinar.out");
long long n, temp, i, S, c, z, u;
int main() {
    in >> n;
    for (i = 1; i <= n; i++) {
        in >> temp;
        S = 0;
        z = 0;
        u = 0;
        c = temp % 2 ;
        temp = temp / 2 ;
        if (c == 0) z++;
        else u++;
        while (temp != 0) {
            c = temp % 2 ;
            if (c == 0) S = S + u ;
            else S = S + 3 * u + 2 * z ;
            if (c == 0) z++;
            else u++;
            temp = temp / 2 ;
        } out << S << " " ;
    } return 0;
}