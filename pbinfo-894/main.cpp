void cifminmax(int n, int &Max, int &Min) {
    if (n < 9) Max = Min = n;
    else {
        Max = -1, Min = 10;
        while (n > 0) {
            if (n % 10 > Max) Max = n % 10;
            if (n % 10 < Min) Min = n % 10;
            n = n / 10;
        }
    }
}