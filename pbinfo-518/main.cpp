#include <iostream>
using namespace std;
int main() {
	int v[10001], n, st = 0, dr = 0, lungime = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i) {
		if (v[i] == 0) {
			int temp = 0;
			for (int j = i; v[j] == 0 && j <= n; ++j) temp++;
			if(temp > lungime) {
				st = i;
				dr = i + temp - 1;
				lungime = temp;
			}
		}
	} cout << st << " " << dr;
	return 0;
}
