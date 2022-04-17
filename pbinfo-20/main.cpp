void sum_div_prim(int nr, int& suma) {
    suma = 0;
    int temp = 2;
    while (nr > 1) {
        if (nr % temp == 0)
            suma = suma + temp;
        while (nr % temp == 0)
            nr = nr / temp;
        temp++;
        if (nr > 1 && temp * temp > nr) {
            suma = suma + nr;
            nr = 1; 
        }
    }
}