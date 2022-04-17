#include <iostream>
using namespace std;
int main() {
	int n, S; cin >> n;
    S = n * (n + 1) * (n + 2) / 6;
	cout << "Rezultatul este " << S;
	return 0;
}