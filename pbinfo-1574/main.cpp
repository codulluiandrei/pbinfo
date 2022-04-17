#include <iostream>
using namespace std;
int main () {
    int a, b, S1 = 0, S2 = 0;
    cin >> a >> b;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            S1 = S1 + i;
            S1 = S1 + (a / i);
        } if (i * i == a) S1 = S1 - i;
    } S1= S1 - a;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            S2 = S2 + i;
            S2 = S2 + (b / i);
        } if (i * i == b) S2 = S2 - i;
    } S2 = S2 - b;
    if (S1 == b && S2 == a) cout << "PRIETENE";
    else cout << "NU SUNT PRIETENE";
    return 0;
}