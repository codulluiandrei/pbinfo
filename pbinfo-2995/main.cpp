void inserare(int &n) {
    int m = n % 10, c = n % 10, p = 10;
    n = n / 10;
    while (n > 0) {
        int c1 = n % 10;
        n = n / 10;
        m = m + abs(c1 - c) * p + c1 * p * 10;
        p = p * 100;
        c = c1;
    } n = m;
}