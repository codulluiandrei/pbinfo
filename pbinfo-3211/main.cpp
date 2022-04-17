#include <bits/stdc++.h>
using namespace std;
int main() {
    int S, c, n;
    cin >> S >> c >> n;
    if (S % c == 0 && S % n != 0)
        cout << "C";
    else if (S % c != 0 && S % n == 0)
        cout << "N";
    else if (S % c == 0 && S % n == 0)
        cout << "CN";
    else
        cout << "nimic";
    return 0;
}