int sumcif(int x) {
    int nrcif = 0, temp = x, S = 0;
    while (temp != 0) {
        nrcif++;
        temp = temp / 10;
    } for (int i = 1; i <= nrcif; ++i) {
        temp = x % 10;
        x = x / 10;
        S = S + temp;
    } return S;
}