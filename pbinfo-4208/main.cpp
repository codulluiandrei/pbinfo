int ExistaImpareRec(int n)
{
    if (n < 10) return (n % 2 == 1);
    return (n % 2) || ExistaImpareRec(n / 10);
}