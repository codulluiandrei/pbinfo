void duplicare(int &n) {
    int copie = n, p = 1;
    n = 0;
    while (copie) {
        if (copie % 2 == 0)
            n = n + copie % 10 / 2 * p, p = p * 10;
        n = n + copie % 10 * p, p = p * 10;
        copie = copie / 10;
    }
}