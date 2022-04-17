#include <bits/stdc++.h>
using namespace std;
long long nrInv;
int a[100005], n, b[100005];
void Interclasare(int p, int m, int q) {
    int i, j, k;
    i = p; j = m + 1; k = 0;
    while (i <= m && j <= q)
        if (a[i] <= a[j]) b[++k] = a[i++];
        else {
            nrInv += (m - i + 1);
            b[++k] = a[j++];
        } while (i <= m) b[++k] = a[i++];
    while (j <= q) b[++k] = a[j++];
    j = p;
    for (i = 1; i <= k; i++) a[j++] = b[i];
}
void Schimbare(int i, int j) {
    int temp;
    if (a[i] > a[j]) {
        nrInv++;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void MergeSort(int p, int q) {
    int m;
    if (q - p <= 1) Schimbare(p, q);
    else {
        m = (p + q) / 2;
        MergeSort(p, m);
        MergeSort(m + 1, q);
        Interclasare(p, m, q);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    MergeSort(1, n);
	cout << nrInv;
    return 0;
}