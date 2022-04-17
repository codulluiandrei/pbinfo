int suma(int v[], int n, int m) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
    int suma = 0;
    for (int i = 0; i < m; i++) suma = suma + v[i];
    return suma;
}