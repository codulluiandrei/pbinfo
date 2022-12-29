int minDivPrim(int n) {
    int rez = 1, d = 2;
    while (n > 1) {
        if (n % d == 0) {
            rez = rez * d;
            while (n % d == 0)
                n = n / d;
        } d++;
        if (d * d > n) d = n;
    } return rez;
}