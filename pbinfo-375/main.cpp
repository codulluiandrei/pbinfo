#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
    if (n == 1) {
        cout << 2;
        return 0;
    }
    if (n % 2 == 0) n++;
    else n += 2;
    while(true) {
            if (n > 1 && (n % 2 != 0 || n == 2)) {
                    int radical = sqrt(n), temp;
                    for(temp = 3; temp <= radical; temp += 2)
                        if(n % temp == 0)
                            break;
                    if(temp > radical)
                        break;
                } n += 2;
        } cout << n;
}