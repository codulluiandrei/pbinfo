#include <iostream>
#include <math.h>
using namespace std;
int main () {
    int n; cin >> n;
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            cout << i << " ";
            cout << n / i;
            break;
    	}
    } return 0;
}
