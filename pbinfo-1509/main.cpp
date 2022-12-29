int nrmaxim(int n) {
    int nrcif = 0, p = 1 , m = n;
    while (m) {
        nrcif++, p = p * 10, m = m / 10;
    } int maxim = 0;
    p = p / 10;
    while (nrcif) {
        if (n > maxim)
            maxim = n;
        n = n % p * 10 + n / p;
        nrcif--;
    } return maxim;
}