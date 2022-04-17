#include <fstream>
using namespace std;
ifstream in("error.in");
ofstream out("error.out");
long long n, i, j, r, a, b, c[31], t;
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> a >> b ;
        r = a % b ;
        for (int j = 1; j <= 30; j++) {
            c[j] = c[j] + (r * 10) / b ;
            r = ( r * 10 ) % b ;
        }
    } t = 0;
    for (int j = 30; j >= 1; j--) {
        r = (c[j] + t) % 10;
        t = (c[j] + t) / 10;
        c[j] = r ;
    } for (int j = 1; j <= 20; j++) 
        out << c[j] << " " ;
    return 0;
}