#include <fstream>
using namespace std;
ifstream in("3lan.in");
ofstream out("3lan.out");
int n;
int main() {
    in >> n;
    out << 7 * n * (n - 1) / 2;
    return 0;
}