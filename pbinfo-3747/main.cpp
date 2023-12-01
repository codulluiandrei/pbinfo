/** Diana
	complexitate timp: O(K)
	memorie suplimentară: O(K)
**/
#include <fstream>

using namespace std;

ifstream fin("bile4.in");
ofstream fout("bile4.out");


const int NMAX = 100000;
const int KMAX = NMAX / 2;

int C, N, K;
int s[KMAX];


void scrie() {
	for (int i = 0; i < K; i++)
		fout << s[i] << ' ';
	fout << '\n';
}


// numărul X al bilei speciale din cutia A
void c1() {
	if (N % 2 == 1) fout << (N - 1) / 2 << '\n';
	else fout << -1 << '\n';
}

// cel mai mic șir lexicografic
void c2() {
	long long K_patrat = (long long)K * (long long)K;
	long long S = 0;

	for (int i = 0; i < K - 1; i++) {
		s[i] = i;
		S += s[i];
	}

	if (K_patrat - S <= N - 1) {
		s[K - 1] = K_patrat - S;
		scrie();
		return;
	}

	s[K - 1] = K - 1;
	S += s[K - 1];

	int dif = K_patrat - S;
	int g = dif / (N - K);
	int rest = dif % (N - K);

	for (int i = 1; i <= g; i++)
		s[K - i] += (N - K);

	if (s[K - (g + 1)] + rest != K)
		s[K - (g + 1)] += rest;
	else {
		s[K - (g + 1)] += (rest + 1);
		s[K - g] -= 1;
	}

	scrie();
}

void c3() {
	if (K % 2 == 0) {
		// K par
		int m = K / 2;
		for (int i = 0; i < K; ++i) {
			s[i] = m;
			++m;
			if (m == K) ++m;
		}
		scrie();
		return;
	}

	// K impar
	int M = K / 2;
	s[0] = M;
	s[K - 1] = 2 * K + 1 - s[0];
	s[M] = K - 1;

	for (int i = 1, j = K - 2; i < M; ++i, --j) {
		s[i] = M + i;
		s[j] = 2 * K - s[i];
	}

	scrie();
}


int main() {
	fin >> C >> N >> K;

	if (C == 1) c1();
	else if (C == 2) c2();
	else if (C == 3) c3();

	return 0;

}
