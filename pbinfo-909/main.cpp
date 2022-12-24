void perm(int &n) {
    int p = 1, x = n;
    while (x > 9)
        p = p * 10, x = x / 10;
    n = n % p;
    n = 10 * n + x;
}