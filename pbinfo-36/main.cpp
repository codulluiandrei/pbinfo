int prim(int n){
    if (n < 2) return 0;
    if (n % 2 == 0 && n > 2) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            return 0;
    return 1;
}
int i_prim(int n) {
    int x, y;
    x = y = n;
    while (!prim(y)) --y;
    while(!prim(x)) ++x;
    return x - y;
}