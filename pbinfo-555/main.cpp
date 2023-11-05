#include <iostream>
#include <string>
using namespace std;
int n;
unsigned long long a, b;
const unsigned long long lim = -1;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if ((a && lim / a >= b) || (b && lim / b >= a) || (!a && !b))
            cout << a * b << "\n";
        else
            cout << "Overflow!\n";
    } return 0;
}