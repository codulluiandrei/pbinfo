#include <bits/stdc++.h>
using namespace std;
int n, v[100005];
void QuickSort(int st, int dr) {
    if (st < dr) {
        int m = (st + dr) / 2;
        int temp = v[st];
        v[st] = v[m];
        v[m] = temp;
        int i = st, j = dr, d = 0;
        while (i < j) {
            if (v[i] > v[j]) {
                temp = v[i]; 
                v[i] = v[j];
                v[j] = temp;
                d = 1 - d;
            } i += d;
            j -= 1 - d;
        }
        QuickSort(st, i - 1);
        QuickSort(i + 1, dr);
    }
}
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i ++) cin >> v[i];
    QuickSort(0, n - 1);
    for (int i = 0 ; i < n ; i ++) cout << v[i] << " ";
    return 0;
}