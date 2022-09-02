int DivImpar(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    } while (a % 2 == 0)
        a = a / 2;
    return a;
}