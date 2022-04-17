int multipli(int a, int b, int c) {
    int afisare = b / c - a / c;
    if (a % c == 0) afisare++;
    return afisare;
}