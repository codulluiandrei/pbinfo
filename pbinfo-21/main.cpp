void sum_cif(int n, int& suma) {
    suma = 0;
    while (n){
        suma = suma + (n % 10);
        n = n / 10;
    }
}