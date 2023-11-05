#include <fstream>
using namespace std;
ifstream in("nrasoc.in");
ofstream out("nrasoc.out");
int main() {
    int x, y, z;
    in >> x >> y;
    while (in >> z && x >= z) {
        out << x << " ";
        x = y;
        y = z;
    } if (!in.eof())
        out << z << " ";
    while (in >> z)
        out << z << " ";
    return 0;
}