bool Egal(int n) {
    int cif = 0;
    while (n > 0) {
        if (n % 10 % 2 == 1) {
            cif = n % 10;
            break;
        } n = n / 10;
    }
    while (n > 0) {
        if (n % 10 % 2 == 1 && n % 10 != cif) 
            return 0;
        n = n / 10;
    } return 1;
}