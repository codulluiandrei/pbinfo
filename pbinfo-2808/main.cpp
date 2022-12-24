void produs(int a, int &k) {
    int p = 1;
    k = 1;
    while (p * (k + 2) <= a)
        k = k + 2, p = p * k;
}