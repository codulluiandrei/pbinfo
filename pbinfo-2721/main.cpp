void Insert(int a[], int &n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        k = k + (a[i] % 2);
    int j = n + k - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2) a[j--] = 2 * a[i];
        a[j--] = a[i];
    } n = n + k;
}