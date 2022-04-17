#include <fstream>
using namespace std;
ifstream in("eratostene.in");
ofstream out("eratostene.out");
int n, v[1000001];
int main() {
    v[0] = v[1] = 1;
    for (int i = 2; i * i < 1000001; ++i)
        if (v[i] == 0)
            for (int j = 2; i * j < 1000001; ++j)
                v[i * j] = 1;
    in >> n;
    int x, C = 0;
    for (int i = 1; i <= n; ++i) {
        in >> x;
        if (v[x] == 0) C++;
    } out << C;
    return 0;
}