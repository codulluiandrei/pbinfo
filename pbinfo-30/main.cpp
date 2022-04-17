void sub(int n, int k) {
    for (int i = k * n; i >= k ; i = i - k) {
        cout << i << " ";
    }
}