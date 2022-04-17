#include <bits/stdc++.h>
using namespace std;
long long n, nr, temp1, factorizare, maxim;
int main() {
    cin >> n;
    nr = 2;
    do {
        temp1 = 0;
        while (n % nr == 0) {
            temp1++;
            n = n / nr;
        } if ((temp1 > 0) && (temp1 >= maxim)) {
            maxim = temp1; 
            factorizare = nr;
        } nr++;
        if ((n > 1) && (nr * nr > n)) 
            if (maxim > 1) 
            	n = 1;
		else factorizare = n, n = 1;
    } while (n > 1);
    cout << factorizare;
    return 0;
}
