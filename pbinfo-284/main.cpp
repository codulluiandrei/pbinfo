#include <fstream>
using namespace std;
ifstream in("interclasare3.in");
ofstream out("interclasare3.out");
int main() {
    int a[100001], b[100001], c[200001], n, m, k = 0;
    in >> n >> m;
    for (int i = 1; i <= n; ++i) in >> a[i];
    for (int j = 1; j <= m; ++j) in >> b[j];
    int i = 1, j = m;
    while (i <= n && j >= 1) {
        if (a[i] < b[j] && a[i] % 2 == 0) c[++k] = a[i++];
        else if (a[i] < b[j]) i++;
        else if(b[j] % 2 == 0) c[++k] = b[j--];
        else j--;
    } while (i <= n) {
        if (a[i] % 2 == 0) c[++k] = a[i];
        i++;
    } while (j >= 1) {
        if (b[j] % 2 == 0) c[++k] = b[j];
        j--;
    } for (int i = 1; i <= k; ++i) {
        out << c[i] << " ";
        if (i % 20 == 0) out << endl;
    } return 0;
}