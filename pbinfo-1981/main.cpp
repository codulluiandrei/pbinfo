#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long int n, valsir, temp, val, nrdiv;
	cin >> n;
	for (int i = 0; i < n; i++) {
        nrdiv = 1; val = 2;
		valsir = i * pow(2, i) + 1;
		while (valsir > 1) {
			temp = 0;
			while (valsir % val == 0) {
				temp++;
				valsir = valsir / val;
			} nrdiv = nrdiv * (temp + 1);
			val++;
			if (valsir > 1 && val * val > valsir) val = valsir;
		} cout << nrdiv << " "; 
	} return 0;
}