#include <iostream>
using namespace std;
unsigned long long n, A, R, rez = 0, temp;
int main() {
    cin >> n;
    for (unsigned long long int i = 1; i <= n; ++i) {
        cin >> A >> R;
        temp = A * A + 3 * A + 1;
        if (temp == R) rez++;
    } cout << rez;
    return 0;
}