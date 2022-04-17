#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n % 2 + n / 10 % 2 + n / 100 % 2;
    return 0;
}