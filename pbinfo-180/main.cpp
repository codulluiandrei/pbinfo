#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, v[1001], minim = 1000000001, maxim = -1000000001, pozmin = 0, pozmax = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) { 
        cin >> v[i];
        if (v[i] > maxim) {
            maxim = v[i];
            pozmax = i;
        } else if (v[i] < minim) {
            minim = v[i];
            pozmin = i;
    	}
    } if (pozmin > pozmax) swap(pozmin, pozmax);
    sort(v + pozmin, v + pozmax + 1);
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
} // rezolvare cu stl sort