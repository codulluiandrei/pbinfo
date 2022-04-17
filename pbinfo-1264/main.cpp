#include <fstream>
#include <algorithm>
using namespace std; 
ifstream in("statisticiordine.in");
ofstream out("statisticiordine.out");
int main () {
	unsigned int v[4000001], n, k;
    in >> n >> k;
    for (int i = 1; i <= n; i++) in >> v[i];
    sort (v + 1, v + n + 1);
    out << v[k];
    return 0;
}