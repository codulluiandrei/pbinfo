int DivImpRec(int n)
{
    if (n % 2 == 1) return n;
    return DivImpRec(n / 2);
}