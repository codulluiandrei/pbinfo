int det(int n) {
    int p = 1, k = 1;
    while (p < n)
        k++, p = p * k;
    if (p == n) return p;
    int t = p / k;
    if (n - t <= p - n)
        return t;
    else return p;
}