int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0 && n > 2) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0) return 0;
	return 1;
}
void afisare(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } for (int i = a; i <= b; i++)
        if (prim(i))
        	cout << i << " ";
}