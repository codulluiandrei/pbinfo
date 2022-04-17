void sterge(int a[], int& n, int i, int j) {
    int temp = j - i + 1;
    for (int var = j + 1; var <= n; var++)
        a[var - temp] = a[var];
    n = n - temp;
}