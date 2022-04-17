int count(double a[], int n){
    double suma = 0;
    for (int i = 0; i < n; i++)
        suma = suma + a[i];
    suma = (double) suma / n;
    int temp = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= suma)
            temp++;
    return temp;
}