int sum_div(int n) {
    int suma = 0, i = 1;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            suma = suma + n / i;
            suma = suma + i;
        } if (i * i == n) suma = suma - i;
    } return suma;
}