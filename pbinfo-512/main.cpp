#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, v[1001], maxim = -1001, var;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    for (int i = 0; i < n; ++i)
        if (v[i] > maxim) {
        	maxim = v[i];
        	var = i;
        }
    } sort(v, v + var);
    for (int i = 0; i < var; ++i)
    	cout << v[i] << " ";
    sort(v + var, v + n);
    for (int i = n - 1; i >= var; --i)
    	cout << v[i] << " ";
    return 0;
}
