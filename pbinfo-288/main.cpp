#include <iostream>
using namespace std;
int main() {
	int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    	cin >> v[i];
    bool adv = true;
    for (int i = 1; i <= n; ++i)
        if (v[i] % 2 != 0)
        	adv = false;
	if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}