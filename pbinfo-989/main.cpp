#include <fstream>
using namespace std;
ifstream in("sumperm.in");
ofstream out("sumperm.out");
int main() {
    int n, v[15], S = 0, temp = 0;
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> v[i], S = S + v[i];
    for(int i = 1; i <= n; i++) {
        int var = S + temp;
        v[i] = var % 10;
        temp = var / 10;
    } v[n + 1] = temp;
    for (int i = n + 1; i > 0; i--)
        out << v[i];
    return 0;
}