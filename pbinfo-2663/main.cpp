int NrDiv(int n) {
    int i, nrD = 0;
    for (i = 1; i * i < n; i++)
        if (n % i == 0) nrD = nrD + 2;
        if (i * i == n) nrD++;
        return nrD;
}
int NextNrDiv(int n) {
    int i, nrD;
    nrD = NrDiv(n);
    while (1) {
        n++;
        i = NrDiv(n);
        if (i == nrD) return n;
    } return -1;
}
int PrevNrDiv(int n) {
    int i, nrD;
    nrD = NrDiv(n);
    while (n > 1) {
        n--;
        i = NrDiv(n);
        if (i == nrD) return n;
    } return -1;
}