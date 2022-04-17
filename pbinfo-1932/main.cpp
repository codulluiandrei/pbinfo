#include <fstream>
using namespace std;
ifstream in("pc.in");
ofstream out("pc.out");
int n, x, i;
int main() {
    in >> n;
    if (n != 0)
        for (i = 1; i <= n; i++) {
            in >> x;
            if (x % 2 == 1)
                out << "1 ";
            else
                out << "0 ";
        }
    else out << "-1";
    return 0;
}