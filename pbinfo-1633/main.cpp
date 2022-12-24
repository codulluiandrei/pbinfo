void dublare1(int &n) {
    int p = 1, copie = n;
    while (copie > 9) {
        p = p * 10;
        copie = copie / 10;
    } n = n / p * 11 * p + n % p;
}