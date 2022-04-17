void P(int &n, int c) {
    int vec[15];
    int nr = 0;
    while (n){
        if (n % 10 != c)
            vec[++nr] = n % 10;
        n = n / 10;
    } for(int i = 1; i <= nr; --nr) n = 10*n + vec[nr];
}