int Kth(int a[], int n, int x, int k) {
    if (k <= 0) return -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) k--;
        if (k == 0) return i;
    } return -1;
}