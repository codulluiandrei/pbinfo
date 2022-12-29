int echilibrat(int n) {
    int spar = 0, simp = 0, i = 0;
    while (n) {
        if (i % 2 == 0)
            spar = spar + n % 10;
        else
            simp = simp + n % 10;
        i++, n = n / 10;
    } if (spar % 2 == 0 && simp % 2 == 1)
        return 1;
    else return 0;
}