void sumcif(int n, int &s, int &t) {
    t = s = 0;
    while (n) {
        if (n % 10 % 2 == 0)
            s = s + n % 10;
        else
            t = t + n % 10;
        n = n / 10;
    }
}