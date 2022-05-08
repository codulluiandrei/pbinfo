#include <iostream>
using namespace std;
int main() {
    int n, p, q, contorp = 0, contorq = 0, temp;
    cin >> p >> q >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        while (temp % p == 0) {
            temp = temp / p; 
        	contorp++;
        } while (temp % q == 0) {
            temp = temp / q;
        	contorq++;
    	}
    } if (contorp < contorq) cout << contorp;
    else cout << contorq;
    return 0;
}