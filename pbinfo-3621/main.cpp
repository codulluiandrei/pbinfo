int FMBSorted(int a[][2001], int n) {
    int i, j;
    i = 1; j = n;
    while (i <= n && j >= 1)
        if (a[i][j] == 1) j--;
    else i++;
    return (n - j);
}