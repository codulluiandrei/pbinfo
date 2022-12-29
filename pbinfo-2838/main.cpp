int NrPrime(int n) {
    int contor = 0;
    while (n) {
        int c = n % 10;
        if (c == 2 || c == 3 || 
            c == 5 || c == 7)
			contor++;
        n = n / 10;
    }
    return contor;
}