#include <iostream>
using namespace std;
int main() {
    long long int n, doi = 0, trei = 0, nrcif, temp;
    cin >> n; temp = n;
    while (temp != 0) {
    	temp = temp / 10;
        nrcif++;
    } for (int i = 1; i <= nrcif; i++) {
    	temp = n % 10;
        if (temp == 2) doi++;
        else trei++;
        n = n / 10;
    } if (doi > trei) cout << "2";
    else if (doi == trei) cout << "2 3";
    else cout << "3";
	return 0;
}