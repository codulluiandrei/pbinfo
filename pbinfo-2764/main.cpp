#include <bits/stdc++.h>
using namespace std;
int main() {
	int r, g, b, R, G, B;
	cin >> r >> g >> b;
    R = 255 - r;
    G = 255 - g;
    B = 255 - b;
    cout << R << " " << G << " " << B;
    return 0;   
}