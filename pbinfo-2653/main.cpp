long long int nroot(int n, long long int x) {
    return round(pow(max(-x, x), 1.0 / n));
}