#include <bits/stdc++.h>
using namespace std;
int n , v[100005], temp[100005];
void MergeSort(int st, int dr) {
    if (st < dr) {
        int m = (st + dr) / 2;
        MergeSort(st , m);
        MergeSort(m + 1 , dr);
        int i = st, j = m + 1, k = 0;
        while (i <= m && j <= dr)
            if (v[i] < v[j]) temp[++k] = v[i++];
            else temp[++k] = v[j++];
        while (i <= m) temp[++k] = v[i++];
        while (j <= dr) temp[++k] = v[j++];
        for (i = st, j = 1; i <= dr; i++, j++) v[i] = temp[j];
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    MergeSort(0, n - 1);
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}