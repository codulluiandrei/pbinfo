int sum_cifra_control(int a, int b) {
    int S = 0;
    for (int i = a; i <= b; i++) {
        int cc;
        if (i % 9 == 0) cc = 9;
        else cc = i % 9;
        if (cc == a) {
            S++;
        }
    } return S;
}