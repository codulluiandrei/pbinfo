// Problema NiceNumbers - solutie de 100 puncte
#include <iostream>
int main() {
	// Citim q = numarul de numere
	int q;
	std::cin >> q;
	// Citim cele q numere si mentinem variabila ret = numarul de numere "nice"
	int ret = 0;
	while (q--) {
		int val;
		std::cin >> val;
		// ok = numarul este nice (1) sau nu (0)
		bool ok = 0;
		while (val>=10) {
			// daca ultimele doua cifre in acest moment sunt 69, numarul este nice
			if (val%100==69) {
				ok = 1;
			}
			val /= 10;
		}
		// daca numarul este nice, crestem variabila ret
		if (ok) {
			ret += 1;
		}
	}
	// Afisam raspunsul
	std::cout << ret << "\n";
}