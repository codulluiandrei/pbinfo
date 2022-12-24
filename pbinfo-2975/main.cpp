void FRadical(int n, int &x, int &y) {
    for (x = (int)sqrt(n); x > 0; --x) {
        if (n % (x * x) == 0) {
            y = n / (x * x);
            return;
        }
    }
}