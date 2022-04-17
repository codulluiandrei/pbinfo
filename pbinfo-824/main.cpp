int cifmax(int n) {
    if (n < 10) return n;
    else {
        int temp = cifmax(n / 10);
        if (temp > n % 10) return temp;
        else return n % 10;
    }
}