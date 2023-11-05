#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, p, k;
    cin >> n >> p >> k;
    if (pow(10, p + k) / 10 > n) 
        cout << "imposibil";
    else {
        long long int oglinda = 0, putere = 1;
        while (k > 0) {
            oglinda = oglinda * 10 + n % 10;
            putere = putere * 10;
            k--;
            n = n / 10;
        } while (n > pow(10, p)) {
            oglinda = putere * (n % 10) + oglinda;
            putere = putere * 10;
            n = n / 10;
        } long long int oglindatemp = 0;
        while (n > 0) {
            oglindatemp = oglindatemp * 10 + n % 10;
            n = n / 10;
        } oglindatemp =oglindatemp * putere + oglinda;
        cout << oglindatemp;
    } return 0;
}