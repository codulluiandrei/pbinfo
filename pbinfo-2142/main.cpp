# include <fstream>
using namespace std;
ifstream in("easy_sum.in");
ofstream out("easy_sum.out");
int v[100001], n;
long long S;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    for (int i = 1; i <= n; ++i)
        S = (S + 1LL * v[i] * i * (n - i + 1)) % 1000000007;
    out << S << "\n";
    return 0;
}
