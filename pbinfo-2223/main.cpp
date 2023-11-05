#include <iostream>
using namespace std;
int n, S = 0;
int main() {
    cin >> n;
    while (n != 0) {
        S = S + n % 10 ;
        n = n / 10;
    } if (S < 10) {
        cout << S;
        for (int i = 1; i < S; i++) 
            cout << 0;
    } else {
        int c = S / 9;
        int r = S % 9;
        for (int i = 1; i <= c; i++)
            cout << 9;
        cout << r;
        for (int i = 1; i <= S - c - 1; i++)
            cout << 0 ;
    } return 0;
}