#include <iostream>
using namespace std;
int sumcif(int n) {
    int s = 0;
    while (n) {
    	int cif = n % 10;
        s = s + cif;
        n = n / 10;
    } return s;
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
	int n, contor = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
    	int temp; cin >> temp;
        if (prim(temp)) {
        	int scif = sumcif(temp);
        	if (prim(scif)) contor++;
        }        
    } cout << contor;
	return 0;
}