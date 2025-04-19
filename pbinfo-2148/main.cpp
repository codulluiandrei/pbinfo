#include <fstream>
#include <cassert>
using namespace std;
#define MAXN 5000010
int Base[MAXN];
int N;
int ans;
int main() {
	ifstream in("adn.in");
	ofstream out("adn.out");
	in >> N;
	assert(N<=5000000 && N > 0);
	for (int i = 1; i <= N; ++i)
		Base[i] = 1;
	for (int i = 1; i <= N; ++i) {
		if (Base[i] != 1) continue;
		for (int j = i; j <= N; j += i)
			Base[j] *= i;
	}
	for (int i = 1; i <= N; ++i)
		ans += (N / Base[i]);
	out << ans;
	return 0;
}