#include <fstream>
using namespace std;
ifstream in("interclasm.in");
ofstream out("interclasm.out");
int a[100001], b[100001], c[200001], n, m, x, i = 1, j = 1, k = 0;
int main() {
    in >> x >> n;
    for (int i = 1; i <= n; i++) in >> a[i];
    in >> m;
    for (int j = 1; j <= m; j++) in >> b[j];
    i = 1; j = 1; k = 0;
    while (i <= n && j <= m)
        if (a[i] < b[j])
            if (a[i] % x == 0) c[++k] = a[i], i++;
            else i++;
        else if (a[i] > b[j])
                if (b[j] % x == 0) c[++k] = b[j], j++;
                else j++;
            else i++, j++;
    if (i <= n)
        while (i <= n)
            if (a[i] % x == 0) c[++k] = a[i], i++;
            else i++;
    else while (j <= m)
            if (b[j] % x == 0) c[++k] = b[j], j++;
                else j++;
    for (int t = 1; t <= k; t++)
        out << c[t] << " ";
    return 0;
}