int prim(int n) {
    if (n < 2) return 0;
    if (n != 2 && n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
} int a_prim(int n) {
    if (n < 6) return 0;
    int temp = 2;
    while (n % temp != 0 || !prim(temp)) {
        temp++;
        if (temp * temp > n) return 0;
    } n = n / temp;
    if (n == temp) return 0;
    return prim(n);
}