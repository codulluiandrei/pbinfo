int nz(int n) {
    int temp1 = 0, temp2 = 0, temp3 = 2, temp4 = 5;
    while (temp3 < n) {
        temp2 = temp2 + n / temp3;
        temp3 = temp3 * 2;
    } while (temp4 < n) {
        temp1 = temp1 + n / temp4;
        temp4 = temp4 * 5;
    } return temp1;
}