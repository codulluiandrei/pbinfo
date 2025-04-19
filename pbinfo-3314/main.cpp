#include <fstream>
using namespace std;
ifstream cin("eratostene3.in");
ofstream cout("eratostene3.out");
int F[1000001];
int main() {
	int Q; cin >> Q;
	for (int i = 1; i <= 1000000; i++) F[i] = i;
	for (int i = 2;  i <= 1000000; i++)
		if (F[i] == i) {
			F[i]--;
			for (int j = 2; j * i <= 1000000; j++)
				F[j * i]= F[j * i] / i * (i - 1);
		}
	for (int q = 1; q <= Q; ++q) {
		int temp; cin >> temp;
		cout << F[temp] << " ";
	} return 0;
}