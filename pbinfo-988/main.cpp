#include <fstream>
using namespace std;
ifstream in("prime.in");
ofstream out("prime.out");
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            return 0;
    return 1;
}
int main() {
    int n, v[1005];
    in >> n;
    for (int i = 0; i < n; i++)
		in >> v[i];
    for (int i = 0; i < n; i++)
        if (prim(v[i]))
			out << v[i] << " ";
    return 0;
}