double nreal(int n, int m) {
    int a = m, p = 1;
    while (a) {
        p = p * 10;
        a = a / 10;
    } double nr;
    nr = p * n + m;
    nr = (double) nr / p;
    return nr;
}