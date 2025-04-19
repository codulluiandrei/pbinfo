#include <iostream>
using namespace std;
int main() {
	int n, S = 0, ogl = 0;
    cin >> n;
    while (n) {
    	S = S + n % 10;
        n = n / 10;
    } while (S) {
    	ogl = ogl * 10 + S % 10;
        S = S / 10;
    } cout << ogl;
    return 0;
}