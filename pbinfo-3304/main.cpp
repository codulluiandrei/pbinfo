#include <iostream>
#include <algorithm>
using namespace std;
int v[101], n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    int rez = 2020, contor = 0;
    for (int j = n; j > 1; --j) {
        int tempvar = 2020;
    	for (int i = j; i >= 1; --i)
        	if (tempvar % v[i] == 0 && v[i] != 0)
            	tempvar = tempvar / v[i], contor++;
        rez = min(tempvar, rez);
    } if (rez == 1) cout << "DA";
    else cout << "NU";
    return 0;   
}