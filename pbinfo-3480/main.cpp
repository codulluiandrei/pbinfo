#include <fstream>
using namespace std;
ifstream in("9lan.in");
ofstream out("9lan.out");
int n;
int main() {
    in >> n;
    if (n == 0) out << 1;
    else {
        if (n % 2 == 1) out << 9;
        if (n % 2 == 0) out << 1;
    } return 0;
}