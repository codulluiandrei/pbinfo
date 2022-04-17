#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m, temp = 1; cin >> n >> m;
    cout << temp << " ";
    if (n == 1) {}
    else while (temp * n <= m) {
        	temp *= n;
        	cout << temp << " ";
    	}
}