int poz(int x1, int y1, int l1, int i1, int x2, int y2, int l2, int i2) {
    int rez = -1;
    if (x1 > x2 && y1 > y2 && y1 + i1 < y2 + i2 && x1 + l1 < x2 + l2) rez = 0;
    else if (x1 < x2 && y1 < y2 && y1 + i1 > y2 + i2 && x1 + l1 > x2 + l2) rez = 0;
    else if (x1 == x2 && y1 == y2 && i1 == i2 && l1 == l2) rez = 1;
    else if (y2 + i2 < y1) rez = 2;
    else if (y1 + i1 < y2) rez = 2;
    else if (x1 + l1 < x2) rez = 2;
    else if (x2 + l2 < x1) rez = 2;
    else rez = 3;
    return rez;
}