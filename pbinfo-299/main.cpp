#include <fstream>
using namespace std;
ifstream in("sumesecv.in");
ofstream out("sumesecv.out");
int main() {
	int v[10001], n, val, inc, sf;
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> v[i];
	in >> val;
	for (int i = 1; i <= val; ++i) {
		int S = 0;
		in >> inc >> sf;
		for (int j = inc; j <= sf; ++j)
			S = S + v[j];
		out << S << " ";
	} return 0;
}
