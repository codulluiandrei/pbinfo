#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b, d;
    cin >> a >> b >> d;
    int temp1, temp2;
    temp1 = a / d;
    temp2 = b / d;
    if (a % d != 0) temp1++;
    if (b % d != 0) temp2++;
    cout << temp1 * temp2;
    return 0;
}