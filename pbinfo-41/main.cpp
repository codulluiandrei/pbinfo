int F(int n , int a[] , int& k) {
    k = 0;
    bool adv = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            adv++;
            k = k * 10 + a[i];
        }
    } if(adv == 0)
        k = -1; return 0;
}