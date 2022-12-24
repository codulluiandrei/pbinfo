void duplicare(int n, int &d) {
    d = 0;
    int p = 1;
    bool adv = false;
    while (n) {
        d = d + n % 10 * p, p = p * 10;
        if (n % 2 == 0)
            d = d + n % 10 * p, p = p * 10, adv = true;
        n = n / 10;
    } if (adv == false) d = -1;
}