void numar(int n, int *a, int &k) {
    int minim = a[0], maxim = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxim) maxim = a[i];
        if (a[i] < minim) minim = a[i];
    } int x = minim; k = maxim;
    while (x) {
        k = k * 10;
        x = x / 10;
    } k = k + minim;
}