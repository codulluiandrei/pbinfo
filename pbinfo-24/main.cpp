int oglindit (int n) {
    int x = 0;
    while (n) {
        x = x * 10 + n % 10;
        n = n / 10;
    } return x;
}