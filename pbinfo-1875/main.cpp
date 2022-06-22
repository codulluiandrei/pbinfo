#include <fstream>
using namespace std;
ifstream in("platou1.in");
ofstream out("platou1.out");
int main() {
    int xmin = 10, k = 0, lg = 1, x, y;
    in >> x;
    while (in >> y)
        if (x == y) lg++;
        else {
            if (k < lg) {
                k = lg;
                xmin = x;
            } else if (k == lg && xmin > x)
                xmin = x;
            lg = 1;
            x = y;
        }
    out << k << " " << xmin << endl;
    return 0;
}