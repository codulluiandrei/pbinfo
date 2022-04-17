int interval(int a[], int n) {
    int minim = a[0];
    int maxim = a[n-1];
    if(minim > maxim) swap(minim, maxim);
    int temp = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= minim && a[i] <= maxim)
            temp++;
    return temp;
}