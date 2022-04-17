#include <fstream>
using namespace std;
ifstream in("2lan.in");
ofstream out("2lan.out");
int n;
int main() {
    in >> n;
    if (n == 0) out << 1;
    else {
        if (n % 4 == 1) out << 2;
        if (n % 4 == 2) out << 4;
        if (n % 4 == 3) out << 8;
        if (n % 4 == 0) out << 6;
    } return 0;
}