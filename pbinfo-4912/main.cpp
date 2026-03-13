int FPareImpare(int n, int d = 0) {

    if (n == 0)

        return d;

    if (n % 10 % 2 == 0)

        return FPareImpare(n / 10, d + 1);

    else

        return FPareImpare(n / 10, d - 1);

}
