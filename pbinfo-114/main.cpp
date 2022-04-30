void nr_div_imp(int n, int &k) {
    k = 0;
    int d;
    for (d = 1; d * d < n; d++)
        if (n % d == 0){
            if (d % 2 == 1)
                k++;
            if (n / d % 2 == 1)
                k++;
        }
    if (d * d == n && d % 2 == 1)
        k++;
}