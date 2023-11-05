#include <iostream>
using namespace std;
int main() {
    int n, i;
    cin >> n;
    if (n % 5 == 0) {
        cout << n / 5 << "\nDA\n";
        n = n / 5;
    } else {
        cout << n / 5 + 1 << "\nNU\n";
        n = n / 5 + 1;
    } i = 1;
    while (n > i) {
        n = n - i;
        i++;
    } if (i % 2 == 0)
        cout << "panselute";
    else
        cout<<"micsunele";
    return 0;
}