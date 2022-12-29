int Fibo(int n) {
    if (n < 3) return 1;
    int a = 1, b = 1 , c, i = 2;
    while (i < n) {
        c = a + b;
        a = b;
        b = c;
        if (c % 2 == 1) i++;
    } return c;
}