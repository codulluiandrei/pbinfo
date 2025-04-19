#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("produse.in");
ofstream out("produse.out");
int primacif(int nr) {
	while (nr > 9)
		nr = nr / 10;
	return nr;
}
int adouacif(int nr) {
	while (nr > 99)
		nr = nr / 10;
	return nr;
}
int main() {
	int v[1001], n, cer;
	in >> cer >> n;
	for (int i = 1; i <= n; ++i)
		in >> v[i];
	if (cer == 1) {
		int par = 0, impar = 0;
		for (int i = 1; i <= n; ++i) {
			int copie = v[i];
			int temp = adouacif(copie);
			if (temp % 2 == 0)
				par++;
			else impar++;
		} out << par << " " << impar;
	} else {
		sort(v + 1, v + n + 1);
		for (int t = 1; t < 10; ++t) {
			bool adv = false;
			for (int i = 1; i <= n; ++i)
				if (primacif(v[i]) == t)
					adv = true;
			if (adv == true) {
				out << t << " ";
				for (int i = 1; i <= n; ++i)
					if (primacif(v[i]) == t)
						out << v[i] << " ";
				 out << "\n";
			}
		}
	} return 0;
}