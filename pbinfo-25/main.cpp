int cmmnr(int n) {
    int v[11], temp = 0;
    while (n){
        v[++temp] = n % 10;
        n = n / 10;
    } for (int i = 1; i < temp; i++)
        for (int j = i + 1; j <= temp; j++)
            if (v[i] < v[j])
                swap (v[i], v[j]);
    for (int i = 1; i <= temp; i++)
        n = n * 10 + v[i];
    return n;
}