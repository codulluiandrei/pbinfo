#include <bits/stdc++>
using namespace std;

ifstream in("suma-cifrelor.in");
ofstream out("suma-cifrelor.out");

int main() {
	int a, suma = 0;
	in >> a;
	while (a > 0) {
		suma = suma + a % 10;
		a = a / 10;
	} out << suma;
	return 0;
}