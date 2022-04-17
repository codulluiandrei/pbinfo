#include <fstream>
using namespace std;
ifstream in("eratostene0.in");
ofstream out("eratostene0.out");
long long int v[1000001], n;
int main() {
    int i, j;
    for (i = 1; i <= 1000000; i++)
        for (j = i; j <= 1000000; j = j + i)
            v[j] = v[j] + i;
    for (i = 2; i <= 1000000; i++)
        v[i] = v[i] + v[i - 1];
    in >> n;
    while (n--) {
        in >> i >> j;
        out << (v[j] - v[i - 1]) << "\n";
    } return 0;
}