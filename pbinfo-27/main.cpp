int nr_cif_zero(int n) {
    int temp = 0;
    int m = n;
    while (n) {
        if (n % 10 == 0)
            temp++;
        n = n / 10;
    } if (m == 0)
    return 1;
    else return temp;
}