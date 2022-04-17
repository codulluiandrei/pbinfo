int cifmin(int n) {
    if (n < 10) return n;
    else { int x = cifmin(n / 10);
        if (x < n % 10) return x;
        else return n % 10;
    }
}