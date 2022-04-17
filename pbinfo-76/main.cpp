int UCP(int n) {
	int upara;
	if (n == 0) return 0;
	while (n > 0) {
		int upara = n % 10;
        if (upara % 2 == 0) return upara;
        n = n / 10;
	} return -1;
}