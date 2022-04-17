void sum_div(int nr,int &suma) {
    suma = 0;
    for (int temp = 1; temp <= nr; temp++)
        if (nr % temp == 0)
            suma = suma + temp;
}