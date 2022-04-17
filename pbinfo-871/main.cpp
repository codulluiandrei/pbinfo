#include <iostream>
using namespace std ;
int main () {
	int n, c1, c2, temp = 1, nr = 0;
	cin >> n >> c1 >> c2 ;
    if (n == 0) nr = c2;
    else {
		while (n != 0) {
    		if (n % 10 == c1) {
    			nr = nr + c2 * temp;
				temp = temp * 10;
			}
			else {
				nr = nr + (n % 10) * temp; 
				temp = temp * 10;
			}
    		n = n / 10;
    	}
	} cout << nr;
	return 0;
}