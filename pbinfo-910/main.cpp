void prefix(int n, int k, int &x) {
    int p = 1;
    for (int i = 1; i <= k; i++)
        p = p * 10;
    x = n;
    while (x >= p) x = x / 10;
}