void cmmdc(int a, int b, int &r) {
    if (b == 0)
        r = a;
    else 
        cmmdc(b, a % b, r);
}