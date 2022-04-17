#include <fstream>
using namespace std;
ifstream in("devt.in");
ofstream out("devt.out");
int rez[100001], v[100001];
int long long n, k, i, j, z;
int main() {
    in >> n >> k;
    v[1] = 1;
    for (i = 2; i <= n; i++)
        if (v[i] != 1)
        for (j = i * i; j <= n; j = j + i) 
        	v[j] = 1;
    for (i = 1; i <= n; i++) {
        rez[i] = rez[i - 1];
        if (v[i] == 1)
            rez[i]++;
    } for (z = 1; z <= k; z++) {
        in >> i >> j;
        if (v[i] == 1)
            out << rez[j] - rez[i] + 1 << "\n";
        else out << rez[j] - rez[i] << "\n";
    } return 0;
}