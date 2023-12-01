int FiboRec(int x, int y)
{
    if (x <= 0 || y <= 0) return 0;
    if (x > y) return 0;
    if (x == 1 && y == 1) return 1;
    return FiboRec(y - x, x);
}