#include <iostream>
using namespace std;
long long int n, i = 2, S = 0;
int main() {
    cin >> n;
    while (n % i != 0) i++;
    n = n / i;
    S = S + i;
    i = 2;
    while (n % i != 0) i++;
    n = n / i;
    S = S + i + n ;
    cout << S;
    return 0;
}