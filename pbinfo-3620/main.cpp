#include <iostream>
using namespace std;
int main() {
    int n, k = 0, temp;
    cin >> n >> k;
    while (n != 0) {
    	temp = n % 10;
        if (temp > k) {
        	cout << "NU";
            return 0;
        } n = n / 10;
    } cout << "DA";
    return 0;
}