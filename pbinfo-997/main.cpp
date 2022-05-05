#include <fstream>
using namespace std;
ifstream in("reuniune.in");
ofstream out("reuniune.out");
int a[1005], b[1005], c[2005], n, m, p;
int main() {
    in >> n >> m;
    for (int i = 1; i <= n;  ++i)
        in >> a[i];
    for (int i = 1; i <= m;  ++i)
        in >> b[i];
    p = 0;
    for (int i = 1; i <= n; i ++)
        c[++p] = a[i];
    for (int i = 1 ; i <= m ; ++i) {
        bool adv = true;
        for (int j = 1; j <= n && adv; j ++)
            if (b[i] == a[j])
                adv = false;
        if (adv) {
            p++; int j;
            for (j = p; j > 1 && c[j - 1] > b[i]; j--)
                c[j] = c[j - 1];
            c[j] = b[i];
        }
    } for (int i = 1; i <= p; i++)
        out << c[i] << " ";     
    return 0;
}