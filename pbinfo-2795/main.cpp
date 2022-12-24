int resturi(int n, int x, int y, int r) {
    int cx = x, cy = y;
    while (cy != 0) {
        int cr = cx % cy;
        cx = cy;
        cy = cr;
    } long long int m = x / cx * y;
    int contor = n / m;
    if (r > 0  && contor * m + r <= n)
        contor++;
    return contor;
}