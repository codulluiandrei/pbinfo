#include <iostream>
using namespace std;
int oglindit(int n) {
    int ogl = 0;
    while (n) {
    	int cif = n % 10;
        ogl = ogl * 10 + cif;
        n = n / 10;
    } return ogl;
}
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
        	return 0;
	return 1;
}
int main() {
	long long int n, S = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
    	int temp; cin >> temp;
        int ogltemp = oglindit(temp);
        if (prim(ogltemp) == 1) S = S + temp;
    } cout << S;
	return 0;
}