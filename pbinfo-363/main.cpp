#include <iostream>
using namespace std;
int main() {
    int n, temp, S = 0, ind = 0, nrcif= 0;
    cin >> n;
    temp = n;
    while (temp > 0) {
        nrcif++;
        temp = temp / 10;
    } 
    if (nrcif % 2 == 0)
        temp = 0;
    else temp = 1;
    while (n > 0) {
        ind++;
        if (ind % 2 == temp)
            S = S + n % 10;
        n = n / 10;
    } cout << S;
    return 0;
}