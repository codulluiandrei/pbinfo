#include <fstream>
using namespace std;
ifstream in("secvk.in");
ofstream out("secvk.out");
int n, K, v[100001];
int main() {
    in >> n >> K;
    for (int i = 1 ; i <= n; ++i)
        in >> v[i];
    int maxim = 0, dr = 0, S = 0;
    for (int i = 1; i < K; ++i)
        S = S + v[i];
    for (int i = K; i <= n; ++i) {
        S = S + v[i];
        S = S - v[i - K];
        if (S > maxim) {
            maxim = S;
            dr = i;
        }
    } for (int i = dr - K + 1; i <= dr; ++i)
        out << v[i] << " ";
    return 0;
}