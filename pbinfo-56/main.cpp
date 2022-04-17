#include <bits/stdc++.h>
using namespace std;
int main() {
    int C = 0, temp1, temp2; cin >> temp1 >> temp2;
    if (temp1 < 0) temp1 = -temp1;
    if (temp2 < 0) temp2 = -temp2;
    while (temp2) {
        if (temp1 % 10 == temp2 % 10) C++;
        temp1 = temp2;
        cin >> temp2;
        if (temp2 < 0) temp2 = -temp2;
    } cout << C;
    return 0;
}