void cifmaxmin(int n, int &max, int &min) {
    max = -1, min = 10;
    if (n == 0)
        min = max = 0;
    else {
        while (n > 0) {
            if (n % 10 > max)
                max = n % 10;
            if (n % 10 < min)
                min = n % 10;
            n = n / 10;
        }
    }
}