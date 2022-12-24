void Impare(int &n) {
    int oglinda = 0, zero = 0;
    while ((n % 10 == 0) || (n % 10 == 1))
        zero++, n = n / 10;
    while (n > 0) {
        int cif = n % 10;
        if (cif % 2 == 1) {
            cif--;
        } oglinda = oglinda * 10 + cif;
        n = n / 10;
    } while (oglinda > 0)
        n = n * 10 + oglinda % 10, oglinda = oglinda / 10;
    for (int i = 0; i < zero; i++)
        n = n * 10;
}