void nr_cif_zero(int n, int &nr) {
    nr = 0;
    if (n == 0)
        nr = 1;
    else 
        while (n > 0) {
            if (n % 10 == 0) nr++;
            n = n / 10;
        }
}