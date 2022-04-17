int sum3(int v[101], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if (v[i] % 3 == 0)
			suma = suma + v[i];
	} return suma;
}