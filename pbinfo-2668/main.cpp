#include <iostream>
using namespace std;
int a[100002], b[100002], c[100002], n;
void Citire() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
        cin >> c[i];
}
int Comun() {
    int i, j, k;
    i = j = k = 1;
    while (i <= n && j <= n && k <= n) {
        if (a[i] == b[j] && b[j] == c[k]) return a[i];
        if (a[i] < b[j]) i++;
        if (b[j] < c[k]) j++;
        if (c[k] < a[i]) k++;
    }
    return -1;
}
int main() {
    Citire();
    cout << Comun() << "\n";
    return 0;
}
