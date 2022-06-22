#include <fstream>
using namespace std;
ifstream in("platou4.in");
ofstream out("platou4.out");
int main() {
    int x, nr, pi, pf;
    pi = pf = 0;
    x = 0;
    while (in >> nr) {
        x++;
        if (nr % 2 == 0) {
            if (pi == 0) pi = x;
            pf = x;
        }
    } out << pf - pi + 1;
    return 0;
}