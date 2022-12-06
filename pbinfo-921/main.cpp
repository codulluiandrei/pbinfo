void factorial(int n, int &f) {
    if (n == 0)
        f = 1;
    else {
        factorial(n - 1, f);
        f = f * n;
    }
}