int multiplu(int n) {
    int i = sqrt(n);
    while (true) {
        if (i * i % n == 0)
            return i * i;
        ++i;
    }
}