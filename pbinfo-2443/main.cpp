#include <bits/stdc++.h>
using namespace std;
int a[100001], s[100001], maxim[100001];
int cautarebinara(int a[], int n, int val) {
    int st = 1, dr = n;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (val < a[mid]) dr = mid - 1;
        else st = mid + 1;
    } return dr;
}
int main() {
    int n, Q, l, r; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > maxim[i - 1]) maxim[i] = a[i];
        else maxim[i] = maxim[i-1];
    } cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> l >> r;
        int rez1 = cautarebinara(maxim, n, l);
        int rez2 = cautarebinara(s, n, r);
        cout << min(rez1, rez2) << "\n";
    } return 0;
}