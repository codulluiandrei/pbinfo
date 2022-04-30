int nr_cif(int n, int k) {
    int contor = 0;
    while (n) {
        if (n % 10)
            if (k % (n % 10) == 0) 
            	contor++;
        n = n / 10;
    } return contor;
}