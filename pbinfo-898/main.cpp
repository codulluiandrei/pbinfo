int sumfactcif(int n) {
    if (n == 0) return 1;
    int S = 0;
    while (n != 0) {
        int temp = n % 10, prod = 1;
        for (int i = 1; i <= temp; ++i)
            prod = prod * i;
        S = S + prod;
        n = n / 10;
    } return S;
}
