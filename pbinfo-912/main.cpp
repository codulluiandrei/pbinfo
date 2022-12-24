int prim(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0 && n > 2) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0) return 0;
	return 1;
}
void sub(int n, int &x, int &y) {
    x = n - 1; y = n + 1;
    while (!prim(x)) x--;
    while (!prim(y)) y++;
}