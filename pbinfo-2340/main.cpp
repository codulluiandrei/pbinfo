int * sumaMinMax(int * v, int n) {
    int i, Min, Max, s=0;
    Min=Max=v[0];
    for (i=0; i<n; i++) {
        s+=v[i];
        if (Min>v[i]) Min=v[i];
        if (Max<v[i]) Max=v[i];
    }
    int * x = (int*)malloc(sizeof(int)*2);
    x[0]=s-Max;
    x[1]=s-Min;
    return x;
}