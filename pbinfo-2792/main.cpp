int prim(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
}
int interval(int n) {
    while (!prim(n)) n++;
    return n + 1;
}