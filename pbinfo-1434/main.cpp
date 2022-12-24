bool numarPrim(int numar) {
    if (numar % 2 == 0 || numar < 3)
        return (numar == 2);
    for (int d = 3; d * d <= numar; d = d + 2)
        if (numar % d == 0) return false;
	return true;
}
void modificare(int a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (numarPrim(a[i])) {
            int contor = a[i];
            a[i] = a[j], a[j++] = contor;
        }
    }
}