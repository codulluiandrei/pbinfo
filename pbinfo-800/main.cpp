int sumdiv(int n) {
    int S = 0;
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0) {
        	S = S + d;
            if (d * d < n)
                S = S + n / d;
    } return S;
}
void perfect(int x, int y) {
    bool adv = false;
    for (int i = y; i >= x; i--)
        if (sumdiv(i) == 2 * i)
        	cout << i << " ", adv = true;
    if (adv == false) cout << "nu exista";
}