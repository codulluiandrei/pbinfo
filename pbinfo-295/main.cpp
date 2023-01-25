#include <iostream>
using namespace std;
int main() {
	int n, v[1001];
	bool adv = false;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 2; i < n; i++)
		if (v[i - 1] % 2 == v[i] % 2 && v[i] % 2 == v[i + 1] % 2)
			adv = true;
	if (adv == true)
		cout << "DA";
	else 
		cout << "NU";
    return 0;
}