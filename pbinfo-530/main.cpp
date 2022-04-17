#include <iostream>
using namespace std;
int main() {
    int a[100001], b[100001], c[200001], d[200001], n, m, k, l, i, j;
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m; for (int j = 1; j <= m; j++) cin >> b[j];
    i = 1; j = 1; k = 0;
    while (i <= n && j <= m) {
        if (a[i] < b[j]) d[++k] = a[i++];
        else if (a[i] > b[j]) d[++k] = b[j++];
        else i++;
    } while (i <= n) d[++k] = a[i++];
    while (j <= m) d[++k] = b[j++];
    i = 1; j = 1; l = 0;
    while (i <= n && j <= m) {
        if (a[i] == b[j]) c[++l] = a[i++], j++;
        else if (a[i] < b[j]) i++;
        else j++;
    } for (int t = 1; t <= k; t++)
        cout << d[t] << " ";
    cout << endl;
    for (int r = 1; r <= l; r++)
        cout << c[r] << " ";
    return 0;
}