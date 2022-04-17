#include <iostream>
#include <algorithm>
using namespace std;
int n, v[101];
bool adv = true;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
    	cin >> v[i];
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; ++i)
        if (v[i] != i)
        	adv = false;
    if (adv) cout << "DA";
    else cout << "NU";
    return 0;    
}