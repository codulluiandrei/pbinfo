bool TreiCifImp(int n) {
    while (n > 0) {
        if (n % 10 % 2 == 1 && n / 10 % 10 % 2 == 1 && n / 100 % 10 % 2 == 1) 
            return 1;
        n = n / 10;
    }
    return 0;
}