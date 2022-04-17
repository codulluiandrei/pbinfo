#include <iostream>
using namespace std;
int n, k, rez = 0, temp, c;
int main() {
    cin >> n >> k;
    if (k == 2) 
        cout << n;
    else {
    	for (int i = 1; i <= n; i++) {
        cin >> temp;
        bool adv = true;
        while ((temp != 0) && adv == true) {
            c = temp % k;
            if (c > 1)
                adv = false;
            temp = temp / k;
        	} if (adv == true) rez++;
    	} cout << rez;
   	} return 0;
}