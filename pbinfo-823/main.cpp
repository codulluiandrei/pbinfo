int sumcif(int n) {
    if (n == 0)
        return 0;
    else 
        return sumcif(n / 10) + n % 10;
}