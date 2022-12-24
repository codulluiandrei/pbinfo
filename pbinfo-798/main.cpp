void interval(int n, int &a, int &b) {
    int p = 1;
    for (int i = 1; i <= n; i++)
        p = p * i;
    a = p / n + 1;
    b = p * (n + 1) - 1;
}