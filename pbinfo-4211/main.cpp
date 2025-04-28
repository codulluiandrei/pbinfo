int ElimZTRec(int n)
{
    if (n % 10 != 0) return n;
    return ElimZTRec(n / 10);
}