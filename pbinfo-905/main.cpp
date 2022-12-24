void detcifre(int n, int &p, int &u) {
    u = n % 10;
    p = n;
    while (p > 9)
        p = p / 10;
}