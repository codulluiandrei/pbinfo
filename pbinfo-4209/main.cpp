int DifParImpar(int n) {
    int pare = 0, impare = 0;
    if (n == 0)
        return 1;
    else {
        while (n > 0) {
            if (n % 10 % 2 == 0)
                pare++;
            else if (n % 10 % 2 == 1)
                impare++;
            n = n / 10;
        }
    } return pare - impare;
    return 0;
}