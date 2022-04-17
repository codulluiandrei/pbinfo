void shift(int x[] , int n) {
    int temp = x[0];
    for (int i = 1; i < n; i++) {
        x[i - 1] = x[i];
    } x[n - 1] = temp;
}