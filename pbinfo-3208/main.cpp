int bitcmp(unsigned long long a, unsigned long long b) {
    if (!(a - b)) return 0;
    if (!a) return -1;
    if (!b) return 1;
    if (!(a / b)) return -1;
    return 1;
}