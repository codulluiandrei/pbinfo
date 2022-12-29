int Phi(int n) {
    int rez;
    rez = n;
    for (int i = 2; i * i <= n && n != 1; ++i)
        if (n % i == 0) {
        	rez = rez / i * (i-1);
            while (n % i == 0)
                n = n /  i;
    } if (n != 1)
        rez = rez / n * (n - 1);
    return rez;
}