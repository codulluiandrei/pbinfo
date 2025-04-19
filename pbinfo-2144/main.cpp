int diofantic(int n, int v[50002], int a, int b, int c) {
    int contor = 0;
    bool adv, temp = true;
    for (int x = 1; x <= n && temp == true; x++) {
        if (v[x] * v[x] * a <= c)
            temp = true;
        else
            temp = false;
        adv = true;
        for (int y = 1; y <= n && adv == true; y++)
            if (v[x] != v[y]) {
                if (v[x] * v[x] * a + v[y] * v[y] * b == c)
                    contor++;
                else if (v[x] * v[x] * a + v[y] * v[y] * b > c)
                    adv = false;
            }
    } return contor;
}