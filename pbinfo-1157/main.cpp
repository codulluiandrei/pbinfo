#include <bits/stdc++.h>
using namespace std;
int n, v[200005], k;
void QuickSort(int st, int dr, int semn) {
    if (st < dr) {
        int m = (st + dr) / 2;
        int temp = v[st];
        v[st] = v[m];
        v[m] = temp;
        int i = st, j = dr, d = 0;
        while (i < j) {
            if (semn * v[i] > semn * v[j]) {
                temp = v[i]; 
                v[i] = v[j];
                v[j] = temp;
                d = 1 - d;
            } i += d;
            j -= 1 - d;
        } QuickSort(st , i - 1, semn);
        QuickSort(i + 1 , dr , semn);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> v[i];
    QuickSort(1, k , 1);
    QuickSort(k + 1, n, -1);
    for (int i = 1 ; i <= n ; i ++) cout << v[i] << " ";
    return 0;
}