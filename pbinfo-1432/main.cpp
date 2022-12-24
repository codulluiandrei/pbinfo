void aranjare(int v[], int n) {
    int contor = n - 1;
    for (int i = 0; i <= contor; ++i) {
        if (v[i] % 2 == 0) {
            swap(v[i], v[contor]);
            contor--;
            i--;
        }
    }
}