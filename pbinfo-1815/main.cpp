#include <fstream>
#include <math.h>
using namespace std;
ifstream in("unghi.in");
ofstream out("unghi.out");
int main() {
    int n, h, m;
    float uh, um, u;
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> h >> m;
        h = h % 12;
        if (m == 60) {
            m = 0;
            h++;
        } uh = (h * 60 + m) * 0.5;
        um = 6 * m;
        if (uh > um) u = uh - um;
        else u = um - uh;
        if (u < 360 - u)
            out << u << "\n";
        else
            out << 360 - u << "\n";
    } return 0;
}
