int kpn(int a, int b, int k) {
    int contor = 0, i, d;
    if (a == 1) {
        contor = contor + 1;
        i = a + 1;
    } else i = a;
    bool paritate, adv = false;
    for (; i <= b && !adv; ++i) {
        if (i % 2 == 0) paritate = false;
        else paritate = true;
        for (d = 2; d * d < i; ++d)
            if (i % d == 0) {
                if (d % 2 == 1) paritate = !paritate;
                if (i/d % 2 == 1) paritate = !paritate;
            }
        if (d * d == i)
        if (d % 2 == 1)
            paritate = !paritate;
        if ((i % 2 == 0) == paritate) {
            contor = contor + 1;
            if (contor == k) adv = true;
        }
    } if (adv) return i - 1;
    else return -1;
}