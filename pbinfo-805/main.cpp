void valuri(int n, int *v) {
    for (int i = 0, j = 1; i < 2 * n; i = i + 2, j = j + 2) v[i] = j;
    for (int i = 1, j = 2 * n; i < 2 * n; i = i + 2, j = j - 2) v[i] = j;
}