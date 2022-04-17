#include <bits/stdc++.h>
using namespace std;
int main () {
    long long int n;
    long long int minim = 1000001;
    cin >> n;
    if (n > 0)
    minim = n;
    while (n) {
    	cin >> n;
    	if (n > 0 && n < minim) minim = n;
    }

    if (minim == 1000001) cout << "NU EXISTA"; 
    else cout << minim;
    return 0;
}