#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, upara = -1;
    cin >> n;
    do {
        if (n % 2 == 0) { 
            upara = n % 10;
            n = 0;
        } n = n / 10;
    } while(n);
    cout << upara;
    return 0;
}