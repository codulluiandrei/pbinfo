bool prim(int n) {
    int nr = 2, temp = 1;
    while (n > 1) {
        int calc = 0;
        while (n % nr == 0) {
            n = n / nr;
            calc++;
        } temp = temp * (calc + 1);
        nr++;
        if (nr * nr > n) nr = n;
    } return temp == 2;
} 