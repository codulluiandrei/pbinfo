bool prim(int n) {
    int d = 2, temp = 1;
    while (n > 1){
        int p = 0;
        while (n % d == 0) {
            n = n / d;
            p++;
        } temp = temp * (p + 1);
        d++;
        if (d * d > n)
            d = n;
    } return temp == 2;
}
void sub(int n, int& a, int& b) {
    a = -1, b = -1;
    n--;
    while (!prim(n))
        n--;
    a = n;
    n--;
    while (!prim(n))
        n--;
    b = n;
}