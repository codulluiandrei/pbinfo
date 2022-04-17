#include <fstream>
using namespace std;
ifstream in("nrcurat.in");
ofstream out("nrcurat.out");
int curat(int x) {
    int ogl = 0, p = 1, urma = 0;
    while (x != 0) {
        ogl = ogl * 10 + x % 10;
        urma = urma + p * (9 - x % 10);
        p = p * 10;
        x = x / 10;
    } return ogl == urma;
} int main() {
    int x;
    while (in >>x)
        if (curat(x)) out << "1 ";
        else out << "0 ";
    return 0;
}