int CifDiv3Rec(long long int n) {
    int contor = 0;
    if (n == 0)
        return 1;
    else {
        while (n > 0) {
            if (n % 10 % 3 == 0)
                contor++;
            n = n / 10;
        }
    } return contor;
}