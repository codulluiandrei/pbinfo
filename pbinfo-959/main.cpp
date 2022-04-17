#include <fstream>
using namespace std;
ifstream in("secmax.in");
ofstream out("secmax.out");
int main() {
	char X[25100];
	int n, st[25100], dr[25100];
	in >> n;
	st[1] = 1, dr[n] = 1;
	for (int i = 1; i <= n; ++i)
		in >> X[i];
	int rez = 0;
	for (int i = 2; i <= n; ++i) {
		if (X[i - 1] < X[i])
			st[i] = st[i - 1] + 1;
		else st[i] = 1;
	} for (int i = n - 1; i >= 1; --i) {
		if (X[i] > X[i + 1])
			dr[i] = dr[i + 1] + 1;
		else dr[i] = 1;
	} for (int i = 1; i <= n; ++i)
		rez = rez + (st[i] - 1) * (dr[i] - 1);
	out << rez;
	return 0;
}
