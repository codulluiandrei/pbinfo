int zerof(int n) {
    int rez = 0;
    for (int i = 5; i <= n ; i = i + 5) {
        int d = i;
        while (d % 5 ==0)
            rez++, d = d / 5;
    } return rez;
}