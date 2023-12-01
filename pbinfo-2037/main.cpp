// Implementare: Cristi Dospra
// Punctaj: 20p
// Complexitate: O(T * N)

#include <fstream>
using namespace std;

ifstream fin("grea.in");
ofstream fout("grea.out");

int main() {

    int T, N;
	
	fin >> T;
	
	while (T--) {
		fin >> N;
	
		int Sol = 0;
	
		for (int i = 2; i <= N; ++i) {
	
			while (N % i == 0) {
				N /= i;
				Sol++;
			}
		}

		fout << Sol << "\n";
	}

    return 0;
}
