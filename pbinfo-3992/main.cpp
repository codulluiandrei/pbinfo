#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, contor = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int temp;
        cin >> temp;
        if (temp < 100 && temp > 9)
            contor++;
    } cout << contor;
    return 0;
}