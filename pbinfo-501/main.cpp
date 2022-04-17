#include <iostream>
using namespace std;
int main() {
    int n, v[505];
	bool adv = true;
    cin  >> n;  
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) if (v[0] != v[i]) adv = false;
    if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}