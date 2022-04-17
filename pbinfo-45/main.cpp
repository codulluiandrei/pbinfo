#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp = 2, nrdivi = 1; cin >> n;
    while (n > 1){
        int tmp = 0;
        while (n % temp == 0) {
            n = n / temp;
        	tmp++;
    	} nrdivi = nrdivi * (tmp + 1);
        temp++;
        if (temp * temp > n) temp = n;
    } if(nrdivi != 2) cout << "NU";
    else cout << "DA";
    return 0;
}