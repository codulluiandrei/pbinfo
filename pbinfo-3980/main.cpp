#include <iostream>
using namespace std;
int main() {
    int n, minim = 10000000, maxim = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	int temp;
        cin >> temp;
        if (temp < minim)
            minim = temp;
        else if (temp > maxim)
            maxim = temp;
    } cout << maxim + minim;
	return 0;
}