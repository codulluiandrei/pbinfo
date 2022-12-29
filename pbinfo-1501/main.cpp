int norocoase(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0)
        return (b - a) / 2;
    return (b - a) / 2 + 1;
}