void oglindit(int n, int& oglindit) {
    oglindit = 0;
    while (n) {
    	oglindit = oglindit * 10 + n % 10;
    	n = n / 10;
    }
}