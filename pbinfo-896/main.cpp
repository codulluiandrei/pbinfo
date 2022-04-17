int fact(int nr) {
	int factorial = 1;
    for (int i = 1; i <= nr; i++) factorial = factorial * i;
    return factorial;
}