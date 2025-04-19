#include <fstream>
using namespace std;
ifstream in("miny.in");
ofstream out("miny.out");
int freq[10001], ap[10001], v[10001];
int temp, N, P = 1;
int cmmdc(int a, int b) {
	while (a && b)
		if (a > b)  a = a % b;
		else b = b % a;
	return a + b;
}
int main() {
	v[2] = 1;
	for (int i = 3; i <= 10000; i = i + 2)
		v[i] = 1;
	for (int i = 3; i <= 10000; i = i + 2)
		if (v[i] != 0)
			for (int j = 2 * i; j <= 10000; j = j + i)
				v[j] = 0;
	in >> N;
	for (int i = 1; i <= N; i++) {
		in >> temp;
		freq[temp]++;
		P = (P * temp) % 100;
	} for (int i = 2; i <= 10000; i++) {
		if (freq[i])
			if (v[i])
				ap[i] = ap[i] + freq[i];
		else {
			temp = i;
			for (int j = 2; j <= 10000 && temp > 1; j++)
				while (v[j] && (temp % j == 0) && temp > 1) {
					ap[j] = ap[j] + freq[i];
					temp = temp / j;
				}
		}
	} int M = 0; temp = 0;
	for (int i = 2; i <= 10000; i++)
		if (ap[i]) {
			M++;
			temp = cmmdc(temp, ap[i]);
	} out << P / 10 << endl << M << endl;
	for (int i = 2; i <= 10000; i++)
		if (ap[i])
			out << i << " " << ap[i] / temp << endl;
	return 0;
}