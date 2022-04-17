#include <iostream>
using namespace std;
int main() {
    int n, temp;
    cin >> n >> temp;
    int maxim = -1;
    do {
        if (n % temp > maxim) maxim = n % temp;
        n = n / temp;
    } while (n != 0);
    cout << maxim;
    return 0;
}
