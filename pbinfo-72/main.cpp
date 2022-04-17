int suma(int v[], int n, int i, int j) {
    int suma = 0;
    for (i--; i; i--) suma = suma + v[i];
    for (j++; j <= n; j++) suma = suma + v[j];
    return suma;
}