#include <iostream>
using namespace std;
int main() {
    int n, maxpar = -1, minimpar = 10, temp;
    cin >> n;
    while (n != 0) {
    	temp = n % 10;
        if (temp > maxpar && temp % 2 == 0) maxpar = temp;
        else if (temp < minimpar && temp % 2 != 0) minimpar = temp;
        n = n / 10;
    } cout << maxpar * minimpar;
    return 0;
}