int cifreImpare(int n) {
    int rez = 0, p = 1, toate_cifrele_impare = 1, are_cifre_impare = 0;
    while (n) { int c = n % 10;
        if (c % 2 == 0) {
            toate_cifrele_impare = 0;
            rez = rez + c * p;
            p = p * 10;
        } else
            are_cifre_impare = 1;
        n = n / 10;
    }
    if (toate_cifrele_impare) return -1;
    if (are_cifre_impare == false) return -1;
    return rez;
}